#include<stdio.h>
#include<stdlib.h>
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
  new->right =  NULL;
  return new;
};

bool isEmpty(struct stack* top){
  return (top == NULL)? 1 : 0;
}

void push(struct stack **ref, struct tree* t){
  struct stack* s = malloc(sizeof(struct stack));
  if(s == NULL){
    printf("Stack Overflow \n");
    exit(0);
  }
  s->t = t;
  s->next = *ref;
  *ref = s;
}

struct tree* pop(struct stack** ref){
  struct stack* top;
  struct tree* res;
  if(isEmpty(*ref)){
    printf("Stack Overflow \n");
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

void postorder(struct tree* root){
  if(root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

void postorder1(struct tree* root){
  struct tree* current = root;
  struct stack* s = NULL;
  bool done = 0;
  while(!done){
    if(current != NULL){
      push(&s,current);
      current = current->left;
    }
    else{
      if(!isEmpty(s)){
        current = pop(&s);
        current = current->right;
        printf("%d ", current->data);
      }
      else{
        done = 1;
      }
    }
  }
}

int main(){
  struct tree* head = newnode(25);
  head->left = newnode(15);
  head->right = newnode(50);
  head->left->left = newnode(10); 
  head->left->right = newnode(22); 
  head->right->left = newnode(35);
  head->right->right = newnode(70);
  head->left->left->left = newnode(4);
  head->left->left->right = newnode(12); 
  head->left->right->left = newnode(18); 
  head->left->right->right = newnode(24);
  
  head->right->left->left = newnode(31);
  head->right->left->right = newnode(44); 
  head->right->right->left = newnode(66); 
  head->right->right->right = newnode(90);
  
  printf("PostOrder List: ");
  postorder(head);
  printf("\nPostOrder another method: ");
  postorder1(head);
  return 0;
}
