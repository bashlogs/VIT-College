#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};

void display(struct node* n1){
  struct node* head;
  head = n1;
  while( head != NULL){
    printf("\nData: %d", head->data);
    printf("\nAddress: %u", head->next);
    head = head->next;
  }
}

void insertion_at_first(struct node* head, int data){
  struct node* new = NULL;
  new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->next = head;
  head = new;
}

void insertion_at_end(struct node* n1, int data){
  struct node* tail;
  tail = n1;
  struct node* new = NULL;
  new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  tail->next = new;
}

void insertion_at_loc(struct node* n1, int loc, int data){
  for(int i=1;i<loc-1;i++){
    if(n1 != NULL){
      n1 = n1->next;
    }
    else{
      printf("Loc. out of bound");
      break;
    }
  }
  struct node *new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->next = n1->next;
  n1->next = new;
}

int main(){
  struct node* head = NULL;
  struct node* first = NULL;
  struct node* second = NULL;
  struct node* third = NULL;
  
  head = (struct node*)malloc(sizeof(struct node));
  first = (struct node*)malloc(sizeof(struct node));
  second = (struct node*)malloc(sizeof(struct node));
  third = (struct node*)malloc(sizeof(struct node));
 
  head = first;
  first->data = 42;
  first->next = second;
  second->data = 43;
  second->next = third;
  third->data = 34;
  third->next = NULL;
  
  display(head);

  insertion_at_first(head,39);
  printf("\n\nInsertion at first");
  display(head);

  insertion_at_end(third, 20);
  printf("\n\nInsertion at end: ");
  display(head);

  printf("\n\nAfter Insertion at specific location: ");
  insertion_at_loc(head, 10, 59);
  display(head);

  return 0;
}
