#include <stdio.h>
#include <stdbool.h>
int main(){
  int n=5, m=3;
  int alloc[5][3] = {
    {0,1,0},
    {2,0,0},
    {3,0,2},
    {2,1,1},
    {0,0,2}
  };

  int finish[n];
  for(int i=0; i<n; i++){
    finish[i] = 0;
  }

  int max[5][3] = {
    {7,5,3},
    {3,2,2},
    {9,0,2},
    {2,2,2},
    {4,3,3}
  };

  int need[n][m];
  int avail[3] = {3,3,2};
  
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
