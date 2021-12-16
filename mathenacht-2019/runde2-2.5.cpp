// compile: g++ runde2-2.5.cpp
#include <algorithm>
#include <stdio.h>
#include <string>

int main() {
  unsigned int result = 0;
  std::string nums[9] = { "1", "12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789"};

  for (int n=0;n< (sizeof(nums)/sizeof(nums[0]));n++) {
    std::string s = nums[n];
    std::sort(s.begin(), s.end());

    do {
      unsigned int i = std::stoi(s);
      printf("TESTING: %d\n", i);
      result += i;

      for (int j=0;j<s.length();j++) {
        unsigned int k = j+1;
        unsigned int ssai = std::stoi(s.substr(0,k));
        printf("%d / %d\n", ssai, k);
        if (ssai%k != 0) {
          printf("REJECT: %d\n", i);
          result-=i;
          break;
        }
      }
    } while(std::next_permutation(s.begin(), s.end()));
  } 
  printf("\n%d\n", result); // 420265966
  return 0;
}