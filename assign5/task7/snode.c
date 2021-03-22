#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(char *s) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
  struct snode *node1 = (struct snode *)malloc(sizeof(struct snode)); 
  node1->str = (char*)malloc(strlen(s) + 1);
  strcpy(node1->str, s);
  node1->next = NULL; 

  return node1; 
  
}

void snode_destroy(struct snode *s) 
{
free(s->str);
free(s);
 //TODO: implement snode_destroy
 
};