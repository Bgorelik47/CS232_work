#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * head ;
    node_t * node1 ;
    node_t * node2 ;
    node_t * node3 ;

    node1 = malloc(sizeof(node_t));
    node2 = malloc(sizeof(node_t));
    node3 = malloc(sizeof(node_t));

    node1->length = 5;
    node2->length = 5;
    node3->length = 4;

    strcpy(node1->str, "hello");
    strcpy(node2->str, "there");
    strcpy(node3->str, "prof");

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
   return head;
}

void teardown(node_t* head) {
    free(head->next->next);
    free(head->next);
    free(head);
}

void add(node_t ** head, char * str, int length){
    //TODO: implement add to add a new node to front, pointed by head
    node_t * newNode;
    newNode = malloc(sizeof(node_t));
    newNode->length = length; 
    strcpy(newNode->str, str);

    newNode->next = *head;
    *head = newNode;
      
}

void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
  node_t *temp; 
  temp = *head; 

  if(idx == 0){
    *head = temp->next;
    free(temp);
    return;
 }
  for (int i=0; temp!=NULL && i<idx-1; i++){
      temp = temp->next; 
  } 
  node_t *next = temp->next->next; 
  free(temp->next); 
  temp->next = next;
       
} 
void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete. 
 node_t *temp, *prev;
 temp = *head;
 
  while (temp != NULL && (strcmp(temp->str, key) != 0)) {
        prev = temp;
        temp = temp->next;
    } 
  prev->next = temp->next;
  free(temp);  
}
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
