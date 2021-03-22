#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(void *s) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
  struct snode * node1 = (struct snode *)malloc(sizeof(struct snode));
  node1->data = (void *)malloc(strlen((char *)s) + 1);
  strcpy((char*)node1->data, (char*)s);
  node1->next = NULL; 

  return node1; 
  
}

void snode_destroy(struct snode *s) 
{
free(s->data);
free(s);
 //TODO: implement snode_destroy
 
};