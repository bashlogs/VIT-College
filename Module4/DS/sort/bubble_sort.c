#include<stdio.h>

struct stud{
    int roll_no;
    char name[100];
    float cgp;
} s1[10], temp;

int main(){
    int c=0, i=0, pass=0, swap = 0;

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

    for(pass=0;pass<c-1;pass++){
      for(i=0;i<c-pass-1;i++){
        if(s1[i].roll_no > s1[i+1].roll_no){
          swap += 1;
          temp = s1[i];
          s1[i] = s1[i+1];
          s1[i+1] = temp;
        }
      }
    }
  
    printf("\nAfter Sorting: \n");
    for(i=0;i<c;i++){
      printf("Roll No: %d\n", s1[i].roll_no);
      printf("Student Name: %s\n", s1[i].name);
      printf("Student cgp: %f\n", s1[i].cgp);
    }

    printf("\nTotal Swaps: %d", swap);

    return 0;  
}
