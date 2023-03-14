#include<stdio.h>
#include<string.h>

struct rational{
  float num;
  float deno;
};

int gcd(int a, int b){
  if(b == 0){
    return (a);
  }
  else{
    if(a > b){
      gcd (b, a % b);
    }
    else{
      gcd (a,b % a);
    }
  }
}

void reduce(struct rational *p){
  int c = gcd(p->num, p->deno);
  printf("%d\n",c);
  p->num = p->num/c;
  p->deno = p->deno/c;
}

int main(){
  int a,b;
  struct rational p;
  p.num = 10;
  p.deno = 8;
  reduce(&p);

  printf("The value of the p.num = %f\n",p.num);
  printf("The value of the p.deno = %f",p.deno);
  return 0;
}
