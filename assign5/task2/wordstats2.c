#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int counters[7] = {0};
  int i, len = 0;
  char buf[MAX_BUF];
  len = strlen(buf) - 1;
    
   while(fgets(buf,MAX_BUF,stdin)){
     for(i = 0; i <= len; i++)
     {
        if(buf[i] >= 'A' && buf[i] <= 'Z')
        {
          counters[4]++;
        }
        else if(buf[i] >= 'a' && buf[i] <= 'z')
        {
          counters[5]++;
        }
        else if(buf[i]>='0' && buf[i]<='9'){
        counters[6]++;
        }
        else if(buf[i]==' '||buf[i]=='\t'){
        counters[3]++;
        counters[1]++;
        }
        else if(buf[i]=='\n'){
        counters[2]++;
        counters[1]++;
        }
        counters[0]++;
     }
   }

  // chars, words, lines, whitespaces, uppercase, lowercase, digits
    printf("%i %i %i %i %i %i %i\n", counters[0],counters[1],counters[2],counters[3],counters[4],counters[5],counters[6]);
}