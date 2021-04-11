#include <stdio.h>
#include "snode.h"

// global variables (data segment)

struct snode *n1, *n2, *n3, *p;

//------------ MY MAIN FUNCTION --------------------

int main(int argc, char *argv[]) {

  // create snodes
  // TODO: modify func calls to snode_create
  // to match with new prototypes.
  n1 = snode_create("hello");
  n2 = snode_create("there");
  n3 = snode_create("prof");

  printf("snode_test running...\n");

  // manually "link" the nodes together.
  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;

  // p points to node n1 initially
  p = n1;

  while (p != NULL) {
    // Complete this line to print the current node's string and   
    // length (you can use strlen!)
    printf("str: %s - length: %lu\n", (char *)p->data, strlen((char *)p->data)); // TODO
    p = p->next; 
  }
   free(n1->data);
	 free(n1);
	 free(n2->data);
	 free(n2);
	 free(n3->data);
	 free(n3);
  return 0;
}