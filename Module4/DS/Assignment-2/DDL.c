#include<stdio.h>
#include<stdlib.h>

struct Node { 
    int data;
    struct Node *next;
    struct Node *prev;
};

void display(struct Node* node)
{
    struct Node* end;
    while (node != NULL) {
        printf("%d ", node->data);
        end = node;
        node = node->next;
    }
}

void insertStart(struct Node** head, int data){
    
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if(*head != NULL)
        (*head)->prev = newNode;
    
    *head = newNode;   
}

void insertEnd(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        newNode->prev = NULL;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertatpos(struct Node** head, int data, int pos){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    int a =0;
    struct Node* temp = *head;
    newNode->data = data;

    for(int a=1;a<pos;a++){
        if(temp->next == NULL){
            printf("\nPos out of bound");
            return;
        }
        else{
            temp=temp->next;
        }
    }
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    newNode->next = temp;
    temp->prev = newNode;
}

void deletionstart(struct Node** head){
    struct Node* temp = *head;
    if(temp == NULL){
      printf("List is NULL");
      return;
    }
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
    display(*head);
}

void deletionend(struct Node** head){
    struct Node* temp = *head;
    if(temp == NULL){
      printf("List is NULL");
      return;
    }
    struct Node* prev = *head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->prev = NULL;
    free(temp);
    display(*head);
}

void deletionatpos(struct Node** head, int pos){
  struct Node* temp = *head;
  for(int i=1;i<pos;i++){
    if(temp->next == NULL){
      printf("Pos out of bound");
      return;
    }
    else{
      temp = temp->next;
    }
  }
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  free(temp);
  display(*head);
}


int main()
{
    struct Node* head = NULL;
    printf("Insertion at start: ");
    insertStart(&head,1);
    insertStart(&head,9);
    insertStart(&head,10);
    display(head);
    printf("\nInsertion at end: ");
    insertEnd(&head, 43);
    display(head);
    printf("\nInsertion at pos: ");
    insertatpos(&head,54,3);
    display(head);

    printf("\nDeletion at Start: ");
    deletionstart(&head);
    printf("\nDeletion at End: ");
    deletionend(&head);
    printf("\nDeletion at Pos: ");
    deletionatpos(&head,2);

    return 0;
}
