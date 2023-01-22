#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* left;
  struct node* right;
};
struct node* newnode(int data){
  struct node* new = malloc(sizeof(struct node));
  new->data = data;
  new->left = new->right = NULL;
  return new;
}
struct node* insertion(struct node* head, int n){
  if(head == NULL)
    return newnode(n);  

  if(n < head->data){
    head->left = insertion(head->left, n);
  }
  else if(n > head->data){
    head->right = insertion(head->right, n);
  }

  return head;
}

void printlevel(struct node* head, int n){
  if(head == NULL)
    return;
  if(n == 1)
    printf("%d\t");
  else{
    printlevel(head->left, n-1);
    printlevel(head->right, n-1);
  }
}

void display(struct node* head, int n){
  if(head == NULL)
    return;
  else{
    for(int i=0;i<n;i++){
      printlevel(head, n);
    }
  }
}

int height(struct node* head){
  if(head == NULL)
    return 0;

  else{  
    int lheight = height(head->left);
    int rheight = height(head->right);

    if(lheight > rheight)
      return (lheight+1);
    else
      return (rheight+1);
  }
}
void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main(){
  struct node* root = NULL;

  root = insertion(root, 8);
  root = insertion(root, 3);
  root = insertion(root, 1);
  root = insertion(root, 6);
  root = insertion(root, 7);
  root = insertion(root, 10);
  root = insertion(root, 14);
  root = insertion(root, 4);
  inorder(root);
  int n=height(root);
  printf("\n%d",n);
  //int n=height(root);
  //printf("%d",n);
  //display(root, n);
  return 0;
}

