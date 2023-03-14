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
  int b[high+1];
  while( i<=mid && j<=high){
    printf("%d	%d\n",a,b);
    if(a[i] >= a[j]){
      b[k] = a[j];
      j++;
    }
    else{
      b[k] = a[i];
      i++;
    }
    k++;
  }
  while(i<mid)
  	b[k++] = a[i++];
  	
  while(j<high)
  	b[k++] = a[j++];
  	
  for(int i=0; i<high+1; i++)
  {
  	a[i] = b[i];
  }
  
}
void merge1(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
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
  printf("Sorted Array: ");
  print(a, n-1);
  printf("%d", n);
  return 0;
}
