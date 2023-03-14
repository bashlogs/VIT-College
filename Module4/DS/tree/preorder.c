#include <stdio.h>
#include <stdlib.h>
#define bool int

struct tree{
  int data;
  struct tree* left;
  struct tree* right;
};

struct stack{
  struct tree* t;
  struct stack* next;
};

struct tree* newnode(int data){
  struct tree* new = malloc(sizeof(struct tree));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}

void preorder(struct tree* root){
  if(root == NULL)
    return;

  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}

bool isEmpty(struct stack* top){
  return (top == NULL)? 1 : 0;
}
void push(struct stack** ref, struct tree *t){
  struct stack* newnode = malloc(sizeof(struct stack));
  if(newnode == NULL){
    printf("Stack Overflow");
    getchar();
    exit(0);
  }
  newnode->t = t;
  newnode->next = *ref;
  *ref = newnode;
}

struct tree* pop(struct stack** ref){
  struct tree* res;
  struct stack* top;
  if(isEmpty(*ref)){
    printf("Stack Overflow");
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

void preorder1(struct tree* root){
  struct tree *current = root;
  struct stack *s = NULL;
  bool done = 0;
  while(!done){
    if(current != NULL){
      push(&s, current);
      printf("%d ",current->data);
      current = current->left;
    }
    else{
      if(!isEmpty(s)){
        current = pop(&s);
        current = current->right;
      }
      else{
        done = 1;
      }
    }
  }
}

int main(){
  struct tree* head = NULL;
  head = newnode(1);
  head->left = newnode(2);
  head->right = newnode(3);
  head->left->left = newnode(4);
  head->left->right = newnode(5);
  head->right->left = newnode(6);
  head->right->right = newnode(7);
  printf("Preorder List: ");
  preorder(head);
  printf("\nPreorder second list: ");
  preorder1(head);
  getchar();
  return 0;
}

