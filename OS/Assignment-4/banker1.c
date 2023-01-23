#include <stdio.h>
#include <stdbool.h>
int main(){
  int n, m=3;
  printf("Enter how many number processor you want to enter: ");
  scanf("%d",&n);
  int alloc[n][m];
  for(int i=0; i<n; i++){
    printf("\nenter for p%d \n",i+1);
    for(int j=0; j<m; j++){
      printf("p%d.%d: ",i+1,j+1);
      scanf("%d",&alloc[i][j]);
    }
  }
  int finish[n];
  for(int i=0; i<n; i++){
    finish[i] = 0;
  }
  
  int max[n][m];
  printf("\nEnter the max limit of processors: ");
  for(int i=0; i<n; i++){
    printf("\nEnter max limit for p%d \n",i+1);
    for(int j=0; j<m; j++){
      printf("p%d.%d: ",i+1,j+1);
      scanf("%d",&max[i][j]);
    }
  }
  
  int avail[m];
  printf("\nEnter the avialable limit: \n");
  for(int i=0; i<m; i++){
    printf("Available %d: ",i+1);
    scanf("%d",&avail[i]);
  }

  int need[n][m]; 
  for(int i=0; i<n; i++){
    for(int j=0;j<m; j++){
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }
  
  printf("Need: \n");
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%d\t",need[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("Available: \n");
  for(int i=0; i<m; i++){
    printf("%d\t",avail[i]);
  }
  printf("\n\n");
  int seq[n], pos = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(finish[j] == 0){
        int flag=0;
        for(int k=0; k<m; k++){
          if(need[j][k] > avail[k]){
            flag = 1;
            break;
          }
        }
        if(flag == 0){
          seq[pos++] = j;
          for(int y=0;y<m;y++){
            avail[y] += alloc[j][y];
          }
          finish[j] = 1;
        }
      }
    }
  }

  int flag = 1;
  for(int i=0; i<n; i++){
    if(finish[i] == 0){
      flag = 0;
      printf("The following system is unsafe"); 
      break;
    }
  }
  
  if(flag == 1){
    printf("Safe Sequence: ");
    for(int i=0;i<n;i++){
      printf("P%d,",seq[i]);
    }
  }
  return 0;
}

