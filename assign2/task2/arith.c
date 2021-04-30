#include <stdio.h>

#define PI 3.14159


int main()

{

  float r, a;


  printf("Enter radius (in mm):\n");

  scanf("%f", &r);

  r = r/25.4;

  a = PI * r * r;


  printf("Circle's area is %3.2f (sq in).\n", a);


  a = 2 *PI * r;

  printf("Its circumference is %3.2f (in).\n", a);

}
