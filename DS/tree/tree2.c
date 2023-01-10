#include <stdio.h>
#include <conio.h>

struct tree{
  int data;
  struct tree* left;
  struct tree* right;
};

struct tree* newnode(int data){
  struct tree* new = malloc(struct node*);
  new->data = data;
  new->left = NULL;
  new->right = NULL;
}

struct tree* create_tree(int data[]){
  int i=0;
  int size = sizeof(data)/sizeof(data[0]);
  while(i < size){
    
    size++;
  }
}
int main(){
  int a[] = {12,45,9,16,10,18,2,20,8};
  struct tree root = create_tree(a);
}
