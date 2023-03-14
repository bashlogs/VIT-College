#include<stdio.h>
#include<stdlib.h>

struct Node { 
    int data;
    struct Node *next;
    struct Node *prev;
};

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
    *head = (*head)->next;
    (*head)->prev = NULL;
    printf("\nData: %d", temp->data);
    free(temp);
}

void deletionend(struct Node** head){
    struct Node* temp = *head;
    struct Node* prev = *head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->prev = NULL;
    printf("\nData: %d\n", temp->data);
    free(temp);
}

void deletionatpos(struct Node** head, int pos){
  struct Node* temp = *head;
  for(int i=0;i<pos;i++){
    if(temp->next == NULL){
      printf("\nPos out of bound");
    }
    else{
      temp = temp->next;
    }
  }
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  printf("Data: %d", temp->data);
  free(temp);
}

void display(struct Node* node)
{
    struct Node* end;
    while (node != NULL) {
        printf("\nPrev_Address: %u ", node->prev);
        printf("\nData: %d ", node->data);
        printf("\nNext_Address: %u\n", node->next);
        end = node;
        node = node->next;
    }
}
int main()
{
    struct Node* head = NULL;
    printf("\nInsertion List: \n");
    printf("\nInsertion at start: ");
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

    printf("\nDeletion List: \n");
    printf("\nDeletion at Start: \n");
    deletionstart(&head);
    display(head);
    printf("\nDeletion at End: \n");
    deletionend(&head);
    display(head);
    printf("\nDeletion at Pos: \n");
    deletionatpos(&head,1);
    display(head);

    return 0;
}
