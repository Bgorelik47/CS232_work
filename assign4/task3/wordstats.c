#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int i = 0;
  char buf[MAX_BUF];
  
  while(fgets(buf, MAX_BUF, stdin))
  {
   for(int i = 0; i < strlen(buf); i++)
   {
      if (buf[i] >= 'a' && buf[i] <= 'z') 
      {
         buf[i] = buf[i]- 32;
         letter_frequency[buf[i]-'a']++;
      }
      if(buf[i] >= 'A' && buf[i] <= 'Z')
      {
         letter_frequency[buf[i]-'A']++;
      }
   }
  }

  printf("\nDistribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}