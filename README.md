# mathecode

meist (unsauberer) c code der irgendwas ausrechnet. kann komplett falsch liegen, hat bei mir aber funktioniert.

mathenachtaufgaben werden nicht geteilt, da die glaube ich unter copyright liegen.
code der die lösungen berechnet ist hoffentlich ok, da das ja eigentlich nach dem event auch keine*n mehr interessiert.

## file info

* limits
  * folge-grenzwert.c: gibt grenzwert einer folge
  * konvergenz-summe.c: gibt summe einer konvergenz oder so

* mathenacht-2019
  * runde2-2.5.cpp: sucht zahlen n<10 die für jeden substring von 0 bis k (k<=n) durch k teilbar sind und summiert diese auf

* mathenacht-2021 (diese mathenacht hatte sehr viele aufgaben die sich gut mit computer lösen ließen? und die waren alle sehr ähnlich?)
  * runde1-1.3.c: findet quadrupel von primzahlen das eine gleichung erfüllt
  * runde1-1.7.c: findet sextupel von primzahlen das drei gleichunge erfüllt
  * runde1-1.10.c: findet tupel positiver ganzer zahlen das eine gleichung erfüllt

* teiler
  * nteiler.c: war als mathenachtaufgabe geplant, es sollen alle zahlen gefunden werden die genau N teiler haben, quasi die [teileranzahlfunktion](https://de.wikipedia.org/wiki/Teileranzahlfunktion). (mit `./ntt 10000 2 25` kann man z.b. auch alle primzahlen (ungeordnet und außer der 1) von 0 bis 10000 ausgeben (es gibt dafür aber besseren code))
  * nteiler-threaded.c: das gleiche bloß schneller für große zahlenmengen (weil multi-threaded)

## etc

* wenn man code zum mathenachtaufgabenlösen schreibt ist es eigentlich immer so dass wenn dein code mehr als 1 minute läuft ist dein ansatz oder code falsch, meist sind die dinger eher so unter 30 sekunden fertig

* lizenz: alles außer die mathenachtsachen: creative commons cc0
