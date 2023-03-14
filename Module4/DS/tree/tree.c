#include<stdio.h>
#include<stdlib.h>
#define COUNT 5
struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int data){
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

void print_tree(struct Node* head, int space){
  if(head == NULL){
    return;
  }
  space += COUNT;
  print_tree(head->right, space);
  printf("\n");
  for(int i=COUNT; i<space; i++){
    printf(" ");
  }
  printf("%d\n",head->data);
  print_tree(head->left, space);
}
int main(){
  struct Node* head = newNode(84);
  head->left = newNode(43);
  head->right = newNode(38);

  head->left->left = newNode(32);
  head->left->right = newNode(21);

  head->right->left = newNode(25);
  head->right->right = newNode(42);

  print_tree(head, 0);
  return 0;
}
