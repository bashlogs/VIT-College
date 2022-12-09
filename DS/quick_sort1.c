#include <stdio.h>
#include <string.h>

// it follows n log2 n

struct stud{
    int roll_no;
    char name[100];
    float cgp;
}s1[10], temp;

void count(int a){
  if(a == 1){
  	printf("\nTotal No. of swaps: %d", a);
  }
  else{
	  static int count = 0;
	  count = count + 1;
  }
}

void swap(struct stud *a, struct stud *b){
  count(0);
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

void quicksort(struct stud array[], int low, int high){
  if(low < high){
    int pi = portion(array, low, high);
    quicksort(array, low, pi -1);
    quicksort(array, pi+1, high);
  }
}

void printarray(struct stud array[], int n){
  for(int i=0;i<n;i++){
    printf("\nRoll No: %d ",array[i].roll_no);
    printf("\nName: %s ",array[i].name);
    printf("\ncgp: %f ",array[i].cgp);
  }
  printf("\n\n");
}

int main(){
    struct stud s1[10];
    int c=0;
    printf("Enter how many entry you want: ");
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
  quicksort(s1, 0, c-1);
  count(1);
  printf("\n\nSorted Array: ");
  printarray(s1, c);
  return 0;
}
