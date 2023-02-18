#include <stdio.h>
#include <string.h>

// it follows n log2 n

struct stud{
    int roll_no;
    char name[100];
    float cgp;
};

int fun()
{
  static int count = 0;
  count++;
  return count;
}

void swap(struct stud *a, struct stud *b){
  fun();
  struct stud temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int portion(struct stud a[], int p, int q){
  int i = p+1;
  int j = q;
  while(1){
    while(a[i].roll_no < a[j].roll_no){
      i++;
        while(a[j].roll_no >= a[p].roll_no){
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

int portion2(int arr[], int p, int q){
  
    int i = p, j = q;
    int temp;
    int pivot = (p + q) / 2;
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
    if (p < j)
      portion2(arr, p, j);
    if (i < q)
      portion2(arr, i, q);
}

void quicksort(struct stud array[], int low, int high){
  if(low < high){
    int pi = portion(array, low, high);
    quicksort(array, low, pi -1);
    quicksort(array, pi+1, high);
  }
}

void printarray(struct stud array[], int n){
  for(int i=0;i<n;i++){
    printf("\n\n%d Entry",i+1);
    printf("\nRoll No: %d ",array[i].roll_no);
    printf("\nName: %s ",array[i].name);
    printf("\ncgp: %f ",array[i].cgp);
  }
  printf("\n\n");
}

int main(){
  struct stud s1[10];
  int c=0;
  printf("Enter how many number you want to enter: ");
  scanf("%d",&c);
  for(int i=0;i<c;i++){
    printf("%d Entry\n",i+1);
    printf("Enter your roll no: ");
    scanf("%d",&s1[i].roll_no);
    printf("Enter your name: ");
    scanf("%s",s1[i].name);
    printf("Enter your cgp: ");
    scanf("%f",&s1[i].cgp);
  }
  printf("\nUnsorted array: ");
  printarray(s1, c);
  portion2(s1, 0, c-1);
  printf("Sorted Array: ");
  printarray(s1, c);
  printf("\nNumber of Swaps: %d", fun());
  return 0;
}
