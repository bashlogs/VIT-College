#include <stdio.h>

#define SIZE 9

int front = -1;
int rare = -1;
int Queue[SIZE];
void enqueue(int data){
  if(rare == SIZE - 1){
    printf("Queue Overflow\n");
  } 
  else{
    if(front == -1){
        front = 0;
    }
    rare++;
    printf("Enqueue Element: %d\n",data);
    Queue[rare] = data;
  }
}

void dequeue(){
  if(front == -1){
    printf("Queue Empty\n");
  }
  else{
    printf("Dequeue Element: %d\n",Queue[front]);
    front++;
    if(front > rare){
      front = rare = -1;
    }    
  }
}
int main(){
  int a[10] = {10,20,30,40,50,60,70,80,90,100};
  for(int i=0; i<10; i++){
    enqueue(a[i]);
  }
  printf("\n");
  for(int i=0; i<10; i++){
    dequeue();
  }
  return 0;
}

