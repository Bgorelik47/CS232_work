#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int i, index, len;
  char buf[MAX_BUF];
  
do{
  if(fgets(buf, MAX_BUF, stdin) == NULL){
    break;
  }
len = strlen(buf);
index = len - 1; 

  do{
      if (buf[index] >= 'a' && buf[index] <= 'z') 
      {
         buf[index] = buf[index]- 32;
         letter_frequency[buf[index]-'a']++;
      }
      if(buf[index] >= 'A' && buf[index] <= 'Z')
      {
         letter_frequency[buf[index]-'A']++;
      }
   index--;
  }while(index >= 0);

}while(len > 1);


  printf("\nDistribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}