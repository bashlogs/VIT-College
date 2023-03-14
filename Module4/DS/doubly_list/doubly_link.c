#include<stdio.h>
#include<stdlib.h>
struct node{
  struct node *prev;
  int data;
  struct node *next;
};

// void inseartion_at_beginning(struct node* n1, int n){
//   struct node* head = n1;
//   struct node* new;
//   new = (struct node*)malloc(sizeof(struct node));
//   new->data = n;
//   new->prev = head;
//   new->next = head->next;
// }

void display(struct node* n1){
  struct node* head;
  while( n1 != NULL){
    printf("\nData: %d", n1->data);
    head = n1;
    n1 = n1->next;
  }
}

int main(){
  
  struct node* head = NULL;
  struct node* first = NULL;
  struct node* second = NULL;
  struct node* third = NULL;

  head = first;
  first->data = 49;
  first->prev = head;
  first->next = NULL;
  
  second->data = 59;
  second->prev = first;
  second->next = third;
  
  third->data = 69;
  third->prev = second;
  third->next = NULL;

  //inseartion(&head, 54);
  display(head);
  return 0;

}
