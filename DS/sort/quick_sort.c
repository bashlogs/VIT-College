#include <stdio.h>
#include <string.h>

// it follows n log2 n

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int portion(int a[], int p, int q){
  int i = p+1;
  int j = q;
  while(1){
    while(a[i] < a[j]){
      i++;
        while(a[j] >= a[p]){
          j--;
        }
    }
    if(i < j){
      swap(&a[i], &a[j]);
    }
    else{
      swap(&a[i], &a[p]);
      break;
    }
  }
  return j;
}

void quicksort(int array[], int low, int high){
  if(low < high){
    int pi = portion(array, low, high);
    printf("%d \n", pi);
    quicksort(array, low, pi -1);
    quicksort(array, pi+1, high);
  }
}
void printarray(int array[], int n){
  for(int i=0;i<n;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  int a[] = {65,35,78,39,79,18};
  int n = sizeof(a) / sizeof(a[0]);
  printf("Unsorted array: ");
  printarray(a, n);
  quicksort(a, 0, n-1);
  printf("Sorted Array: ");
  printarray(a, n);
  return 0;
}
