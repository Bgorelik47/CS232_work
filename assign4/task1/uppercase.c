#include <stdio.h>

int main(int argc, char *argv[]) {

  char str[10090];
   int n = 0;

   printf("Enter your string "); 
     scanf("%[^\n]", str);


   while (str[n] != '\0' ) {

      if( str[n] >= 'a' && str[n] <= 'z'){

        str[n] = str[n] - 32;

      }
    n++;
   }

  printf("The upper case version is: "); 
  puts(str);



   return 0;



}
