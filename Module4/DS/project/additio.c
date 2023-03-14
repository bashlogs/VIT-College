#include <stdio.h>

int main(){
  int arr[] = {65,35,78,39,78,18};
  int size = sizeof(arr)/sizeof(arr[0]);
  int temp;
  printf("%d\n",size);
  for(int pass=0;pass<size-1;pass++){
    printf("%d pass: ",pass);
    for(int i=0; i<size-pass-1; i++){
      if(arr[i] > arr[i+1]){
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
      }
    }
    for(int i=0; i<size; i++){
      printf("%d ",arr[i]);
    }
    printf("\n");
  }
  printf("Final Pass: ");
  for(int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
}
