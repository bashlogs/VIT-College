#include <stdio.h>

void quickSort2(int *arr, int low, int high)
        {
          int i = low, j = high;
          int temp;
          int pivot = (low + high) / 2;
          while (i <= j)
          {
            while (arr[i] < pivot)
              i++;
            while (arr[j] > pivot)
              j--;
            if (i <= j)
            {
              temp = arr[i]; 
              arr[i] = arr[j];
              arr[j] = temp;
              i++;
              j--;
            }
          }
              if (low < j)
                quickSort2(arr, low, j);
              if (i < high)
                quickSort2(arr, i, high);
        }

int main(){
  int arr[]={32,52,14,35,12,55,32,15,8,56};
  int size = sizeof(arr)/sizeof(arr[0]);
  printf("%d",size);
  quickSort2(&arr,0,size);
  for(int i=0; i<size; i++){
    printf("%d",arr[i]);
  }
  return 0;
}

