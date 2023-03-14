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
    printf("%d ", head->data);
    head = head->next;
  }
}

void insertion_at_first(struct node **head, int data){
  struct node* new = NULL;
  new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->next = *head;
  *head = new;
}

void insertion_at_end(struct node** n1, int data){
  struct node* tail = *n1;
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->next = NULL;
  new->data = data;
  while(tail->next != NULL){
    tail = tail->next;
  }
  tail->next = new;
}

void insertion_at_loc(struct node* n1, int loc, int data){
  int a = 1;
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  for(int i=1;i<loc-1;i++){
    if(n1->next == NULL){
      printf("Loc. out of bound");
      a = 0;
      return;
    }
    else{
      n1 = n1->next;
    }
  }
  if(a == 1){
      struct node *new = (struct node*)malloc(sizeof(struct node));
      new->data = data;
      new->next = n1->next;
      n1->next = new;
  }
}

void deletion_at_first(struct node** n1){
  struct node* temp;
  temp = *n1;
  if(*n1 == NULL){
    printf("Linked List is empty");
    return;
  }

  *n1 = (*n1)->next;
  free(temp);
  display(*n1);
}

void deletion_at_last(struct node* n1){
  struct node* prev;
  struct node* temp;
  temp = n1;
  while(temp->next != NULL){
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  free(temp);
  display(n1);
}

void deletion_at_loc(struct node* n1, int loc){
  struct node* temp = n1;
  struct node* prev;
  for(int i=1;i<loc;i++){
    if(temp->next == NULL){
      printf("\nLoc Doesn't exists");
      return;
    }
    else{
      prev = temp;
      temp = temp->next;
    }
  }
  prev->next = temp->next;
  temp->next = NULL;
  free(temp);
  display(n1);
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
  
  printf("Singly Linked List: ");
  display(head);

  insertion_at_first(&head,39);
  printf("\n\nInsertion at first: ");
  display(head);

  insertion_at_end(&head, 20);
  printf("\n\nInsertion at end: ");
  display(head);

  printf("\n\nInsertion at specific location: ");
  insertion_at_loc(head, 4, 54);
  display(head);
  
  printf("\n\nDeletion at first: ");
  deletion_at_first(&head);

  printf("\n\nDeletion at last: ");
  deletion_at_last(head);

  printf("\n\nDeletion at specific loc.");
  deletion_at_loc(head, 2);
  return 0;
}
