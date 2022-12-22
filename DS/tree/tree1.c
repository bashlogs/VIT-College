#include <stdio.h>
#include <stdlib.h>
#define bool int;

struct tree{
  int data;
  struct tree* left;
  struct tree* right;
};

struct stack{
  struct tree* t;
  struct stack* next;
};


