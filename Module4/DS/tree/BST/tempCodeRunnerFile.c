struct node* newnode(int data){
  struct node* new = malloc(sizeof(struct node));
  new->data = data;
  new->left = new->right = NULL;
  return new;
}