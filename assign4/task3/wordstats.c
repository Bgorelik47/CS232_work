#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

   puts("Type some text (then ENTER):");
  /* Zero out the array */
  int letter_frequency[26] = {0};
  char buf[MAX_BUF];
  int i = 0, len = 0;

  printf("Enter your string "); 
  fgets(buf, MAX_BUF, stdin);
  len = strlen(buf) - 1;
  
  while (buf[i] != '\0') {
   
      if (buf[i] >= 'a' && buf[i] <= 'z') {
        buf[i] = buf[i] - 32;
         len = buf[i] - 'A';
         letter_frequency[len]++;
      }
      else if(buf[i] >= 'A' && buf[i] <= 'Z'){
         len = buf[i] - 'A';
         letter_frequency[len]++;
      }
      i++;
  }
  
  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
      return 0;
}