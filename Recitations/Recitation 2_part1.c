#include <stdio.h>

int power(int base, int exp){

  long result = 1;
  while (exp!= 0){
    result *= base;
    --exp;
  }
  return result;
}

int main(){
  int base2, exp2;
  int result2;
  printf("enter base: ");
  scanf("%d", &base2);
  printf("enter exponent: ");
  scanf("%d", &exp2);
  result2 = power(base2, exp2);
  printf("%d\n", result2);

}