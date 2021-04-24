#include <stdio.h>

#include <stdlib.h>

#include <assert.h>

// Note, the bits are counted from right to left. 

// Return the bit states of x within range of [start, end], in which both are inclusive.

// Assume 0 <= start & end <= 31

unsigned * get_bits(unsigned x, unsigned start, unsigned end) {


 unsigned* a; 

 a = malloc((end-start+1)*sizeof(unsigned int));


 x = x >> start;

 for(int i = 0; i < end; i++)

 {

   a[i] = x%2;

   x = x >> 1;

 }

 return a;

 free(a); 

  // YOUR CODE HERE

  // Returning NULL is a placeholder

  // get_bits dynamically allocates an array a and set a[i] = 1 when (i+start)-th bit of x is 1, otherwise set a[i] = 0;

  // At last, get_bits returns the address of the array.

}
