#include <stdio.h>
#include<string.h>
struct stud{
    int roll_no;
    char name[100];
    float cgp;
};

int main() {
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
    printf("\nOutput Screen: ");
    for(int i=0;i<c;i++){
        printf("\nEnter your roll no: %d\n",s1[i].roll_no);
        printf("Enter your name: %s\n",s1[i].name);
        printf("Enter your cgp: %f\n",s1[i].cgp);
    }

    return 0;
}