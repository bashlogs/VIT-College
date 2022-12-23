#include <stdio.h>
#include <stdlib.h>
#define bool int;

struct tree{
  int data;
  struct tree* left;
  struct tree* right;
};

struct stack{
  struct tree* t;
  struct stack* next;
};

struct tree* newnode(int a){
  struct tree* new = malloc(sizeof(struct tree));
  new->data = a;
  new->left = NULL;
  new->right = NULL;
  return new;
}

bool empty(struct stact* top){
  return (top == NULL ? 1 : 0);
}

void inOrder(struct tree *root){
  struct tree *current = root;
  struct stack *s = NULL;
  bool done = 0;
  while(!done){
    if(current != NULL){
      push(&s, current);
      current = current->left;
    }
    else{
      if(!isEmpty(s)){
        current = pop(&s);
        printf("%d",current->data);
        current = current->right;
      }
      else{
        done = 1;
      }
    }
  }
}

struct tree* pop(struct stack** ref){
  struct tree* res;
  struct stack* top;
  if(isEmpty(*ref)){
    printf("Stack Overflow \n");
    getchar();
    exit(0);
  }
  else{
    top = *ref;
    res = top->t;
    *ref = top->next;
    free(top);
    return res;
  }
}

void push(struct stack** ref, struct tree *t){
  struct stact newNode = malloc(sizeof(struct stack));
  if(newNode==NULL){
    printf("Stack Overflow");
    getchar();
    exit(0);
  }
  newNode->t = t;
  newNode->next = *ref;
  *ref = newNode;
}

int main(){
  struct tree* head = newnode(1);
  head->left = newnode(2);
  head->right = newnode(3); 
  head->left->left = newnode(4); 
  head->left->right = newnode(5);
  head->right->left = newnode(6);
  head->right->right = newnode(7);


  getchar();
  return 0;
}




