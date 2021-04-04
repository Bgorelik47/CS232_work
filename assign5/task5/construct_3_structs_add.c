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

    //TODO:copy setup func from previous task

}

void teardown(node_t* head) {
    free(head->next->next->next);
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

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
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
