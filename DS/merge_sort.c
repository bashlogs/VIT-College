// Merge Sort
#include<stdio.h>
#include<string.h>

void print(int array[], int n){
  for(int i=0; i<n; i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}

void merge(int a[], int low, int mid, int high){
  int i = low;
  int j = mid + 1;
  int k = 0;
  int b[high];
  while( i<=mid && j<=high){
    if(a[i] > a[j]){
      b[k] = a[j];
      j++;
    }
    else{
      b[k] = a[i];
      i++;
    }
    k++;
  }
  if(i > mid){
    for (i=j; i<=high; i++){
      b[k++] = a[i];
    }
  }
  else{
    for(i=j;i<=mid;i++){
      b[k++] = a[i];
    }
  }
  print(b, high);
}
void merge_sort(int array[], int low, int high){
  if(low < high){
    int mid = (low+high) / 2;
    merge_sort(array, low, mid);
    merge_sort(array, mid+1, high);
    merge(array, low, mid, high);
  }
}
int main(){
  int a[] = {65,38,45,78,29,18,83,06};
  int n = sizeof(a) / sizeof(a[0]);
  printf("Unsorted Array: ");
  print(a, n-1);
  merge_sort(a, 0,n-1);
  printf("%d", n);
  return 0;
}
