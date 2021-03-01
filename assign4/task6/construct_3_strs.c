#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char * value; //must use dynamic allocation 
    struct node* next;
} node_t;

node_t * construct_3_strs() {
   struct node* x;
   struct node* y;
   struct node* z;

    x = malloc(sizeof(node_t));
    y = malloc(sizeof(node_t));
    z = malloc(sizeof(node_t));
    
    x->value = (char*)malloc(sizeof(char)* 6);
    y->value = (char*)malloc(sizeof(char)* 3);
    z->value = (char*)malloc(sizeof(char)* 8);

    for(int i = 0; i < 6; i++){
      x->value[i] = "CS232\0"[i];
    }

    for(int i = 0; i < 3; i++){
      y->value[i] = "is\0"[i];
    }
 
    for(int i = 0; i < 8; i++){
      z->value[i] = "awesome\0"[i];
    }

    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 
      x->next = y;
      y->next = z;
      z->next = x;
      
    return x;
    //just to pass compiler, please edit as needed.
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * x = construct_3_strs();
    return dump_all(x);
}

int dump_all(node_t * x) {
    printf("x -> %s", x->value);
    node_t * y = x->next;
    printf(" %s", y->value);
    node_t * z = y->next;
    printf(" %s\n", z->value);
    if(z->next != x) {
        printf("failed");
    return -1;
    } else {
      free(z->value);
      free(y->value);
      free(x->value);
      free(z);
      free(y);
      free(x); 
        return 0;

    }
}