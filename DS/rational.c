#include<stdio.h>

gcd(int a, int b){
  if(a == b){
    return (a);
  }
  else{
    if(a > b){
      a--;
      gcd (a, b);
    }
    else{
      b--;
      gcd (a,b);
    }
  }
}

typedef struct P{
  int num;
  int deno;
}
int main(){
  int a,b;
  c = gcd ()
}
