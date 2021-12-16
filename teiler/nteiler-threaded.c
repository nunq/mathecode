// findet alle zahlen zwischen 0 und N, die genau M teiler haben
// gcc -o ntt -std=c11 -Ofast nteiler-threaded.c -lpthread
// ./ntt BIS_ZAHL(N) ANZAHL_TEILER(M) ANZAHL_THREADS
// nützlich: https://de.wikipedia.org/wiki/Teileranzahlfunktion
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

int nteiler;
unsigned long result, per_thread_span;
mtx_t mutex;

int compute(int tnum) {
  // bereich mithilfe von tnum berechnen
  unsigned long span_start = tnum*per_thread_span+1; // +1, sonst überschneidung
  unsigned long span_end = (tnum+1)*per_thread_span;

  for (unsigned long i=span_start; i<=span_end; i++) {
  int count = 0; // count = 2 funktioniert als optimierung nicht
  //printf("checking %ld\n", i);
    for (unsigned long j=1; j<=i; j++) {
      if (count > nteiler) { // wenn's schon mehr sind, continue;
        continue;
      }
      if (i%j == 0) { // teiler gefunden
        //printf("OK: %ld\n", j);
        count+=1;
      }
    }
    if (count == nteiler) { // zahl mit m teilern gefunden
      mtx_lock(&mutex);
      printf("FOUND: %ld\n", i);
      result += i;
      mtx_unlock(&mutex);
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("usage: ./ntt BIS_ZAHL ANZAHL_TEILER ANZAHL_THREADS\n");
    return 1;
  }

  unsigned long lim = atoi(argv[1]);
  int num_threads = atoi(argv[3]);
  nteiler = atoi(argv[2]);
  result = 0;

  if (lim % (unsigned long) num_threads != 0) {
    printf("%ld %% %d != 0. please adjust the number of threads.\n", lim, num_threads);
    return 1;
  } else {
    per_thread_span = lim/num_threads;
  }

  printf("using segment size of %ld per thread.\n", per_thread_span);

  if (thrd_success != mtx_init(&mutex, mtx_plain)) {
    printf("couldn't initialize mutex. terminating.\n");
  }

  printf("spawning %d threads.\n", num_threads);

  thrd_t tid[num_threads];
  for (int i=0; i<num_threads; i++) {
    if (thrd_success != thrd_create(&tid[i], compute, i)) {
      printf("couldn't create thread #%d. terminating.\n", i+1);
      return 1;
    }
  }

  for (int i=0; i<num_threads; i++) {
    thrd_join(tid[i], NULL);
    printf("range %ld to %ld done.\n", i*per_thread_span, (i+1)*per_thread_span);
  }
  mtx_destroy(&mutex);
  printf("sum: %ld\n", result);
  printf("hex: %lx\n", result);

  return 0;
}
