#include <stdio.h>
#include "snode.h"
#include "slist.h"
#include <string.h>
#include <stdlib.h>

/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
struct slist *slist_create(){
   struct slist *newlist;
   newlist = (struct slist*)malloc(sizeof(struct slist));
   newlist->front = NULL;
   newlist->back = NULL;
   return newlist;
}

/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_back(struct slist *l, void *str){
   struct snode *newnode_back = snode_create(str);
   
   if(l->front == NULL){
     l->front = newnode_back;
   }
   else{
    struct snode *lastnode = l->front;

    while(lastnode->next != NULL){
      lastnode = lastnode->next;
    }

    lastnode->next = newnode_back;  
   }
   
   return newnode_back;
}

/** 
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, void *str){
   struct snode *newnode_front = snode_create(str);
   
   newnode_front->next = l->front;
   l->front = newnode_front; 

   return newnode_front; 
}

/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, void *str){
     struct snode *temp = l->front; 
    
    while(temp != NULL)
    {
         
         if(strcmp(temp->data, str) == 0){
           return temp;
         }
         temp = temp->next;
    }
    
    return NULL;
}

/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l){

   struct snode *current;
   
   while (l->front != NULL) 
   {
       current = l->front;
       l->front = l->front->next;
       snode_destroy(current);
   }
   free(l);
}

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l){
  struct snode *current_node = l->front;

    while(current_node != NULL){
      printf("%s\n", (char*)current_node->data);
      current_node = current_node->next;
    }
}

/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l){
    int count = 0;
    struct snode *current_node = l->front;
    while(current_node != NULL){
      count++;
      current_node = current_node->next;
    }
return count; 
}
/**
 * Deletes the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 */
void slist_delete(struct slist *l, void *str){
     struct snode *temp;
     
      if(strcmp((char*)l->front->data, (char*)str) == 0)
      {
          temp = l->front;    
          l->front = l->front->next;
          free(temp->data);
          free(temp);
      }
      else
      {
          struct snode *current = l->front;
          while(current->next != NULL)
          {
          
              if(strcmp(current->next->data, str) == 0)
              {
                  temp = current->next;
                 
                  current->next = current->next->next;
                  free(temp->data);
                  free(temp);
                  break;
              }
              else
                  current = current->next;
          }
      }
}
