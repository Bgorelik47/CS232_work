#include <stdio.h>
#include <stdlib.h>

int * makearray(int size,int base){

  int *array = malloc (sizeof (int) * size);
  //int array[size];
  int j;

  for(j=0;j<size;j++)
    array[j] = base*=2; //doubling base

  return array;

}

int main(){
  int * a1 = makearray(5,2);
  int * a2 = makearray(10,3);

  int j, sum=0;

  for(j=0;j<5;j++){
    printf("%d ",a1[j]);
    sum+=a1[j];
  }

  free(a1);
  printf("\n");

  for(j=0;j<10;j++){
    printf("%d ",a2[j]);
    sum+=a2[j];
  }
  free(a2);
  printf("\n");
  printf("SUM: %d\n", sum);


}
