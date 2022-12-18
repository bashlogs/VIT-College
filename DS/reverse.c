#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node* next;
};

void insertion_at_first(struct Node** head, int data){
  struct Node* new = malloc(sizeof(struct Node));
  new->data = data;
  new->next = *head;
  *head = new;
}

struct Node* reverse(struct Node* head){
  struct Node* reverse;
  while(head != NULL){
    insertion_at_first(&reverse, head->data);
    //head = head->next;
    head = (head->next == NULL ? break : head->next);
  }
  return reverse;
}

void printlist(struct Node* head){
  printf("List: ");
  while(head != NULL){
    printf("%d\t", head->data);
    head = head->next;
  }
  printf("\n");
}
int main(){
  struct Node* head = NULL;
  struct Node* first = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL; 
  struct Node* fourth = NULL;
  
  first = malloc(sizeof(struct Node)); 
  second = malloc(sizeof(struct Node));
  third = malloc(sizeof(struct Node));  
  fourth = malloc(sizeof(struct Node));

  head = first;
  first->data = 10;
  first->next = second;

  second->data = 20;
  second->next = third;

  third->data = 30;
  third->next = fourth;

  fourth->data = 40;
  fourth->next = NULL;

  printlist(head);
  printlist(reverse(head));
  return 0;
}
