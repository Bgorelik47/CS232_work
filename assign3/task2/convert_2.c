#include<stdio.h>
#include<stdlib.h>
//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
  int A, B, C;
  //int i = 0;
  char *temp;
  C = 0;

  temp = (char*)malloc(39+1);

  if (temp == NULL)
    exit(EXIT_FAILURE);

  for (A = 31 ; A >= 0 ; A--)
  {
    B = dec >> A;

    if (B & 1)
      *(temp+C) = 1 + '0';
    else
      *(temp+C) = 0 + '0';

/*
    if (i%4 == 0){
      i = 0;
      *(temp+C) = *(temp + C) + ' ';
    }
    i++;
    */
    C++;
  }
  *(temp+C) = '\0';
  return  temp;
  	//TODO: your implementation
}

int main() {
	int n;
	char * bin;
	printf("Enter the Decimal Number\n");
	scanf("%d",&n);
	bin = convert_2(n);
	printf("The Binary Notation of %d is \t 0b%s\n", n, bin);

  free(bin);
  return 0;
	//TODO: do we need to release the memory of bin?
}

