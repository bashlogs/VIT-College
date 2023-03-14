#include<stdio.h>
#include<mysql/mysql.h>
#include<string.h>
#include<stdlib.h>

struct customer
{
    int id;
    char *firstname;
    char *lastname;
    long int contactNo;
    float amt;
    int weight;
    int wt;
    float order[4];
}temp;

int check(char username[20], char passowrd[20]);
MYSQL_RES *order5();
void done(int cust);
int * idk3(int no);
MYSQL_RES *order5t();
struct customer *getdata();
int field;

int main(){
  char username[20];
  static float arr[4];
  char password[20];
  int choice;
  MYSQL_RES *result;
  MYSQL_ROW row;
  int num_fields;
  int m=0;
  char *product[4]= {"Wheat","Rice","Olive Oil","Sugar"};
  int price[4] = {30,30,20,50};
  s: printf("Username: ");
     scanf("%s",username);
     printf("Password: ");
     scanf("%s",password);
  
  int c = check(username, password);
  if(c){
    printf("Login Successfull\n");
    goto start;
  }
  else{
    printf("Wrong Username and Password!\n");
    goto s;
  }
  
  start:

  printf("\n1. Show Orders-FCFS\n2. Show Orders-Time\n3. Show all orders-amount \n4. Show all orders-time\n\n");
  printf("Enter your choice: ");
  scanf("%d",&choice);

  switch(choice){
    case 1:
      {
        printf("\n");
        int a=0;
        int cust;
        result = order5();
        num_fields = mysql_num_fields(result);
        while ((row = mysql_fetch_row(result)))
        {
          char *s = row[0];
          int variable;
          sscanf(s, "%d", &variable);
          printf("  Cust Id: %d\n",variable);
          printf("--------------------------------------------------------------\n");
          s = row[3];
          long int variable1;
          sscanf(s, "%ld", &variable1);
          printf("  Name:%s %s             Contact No: %ld              \n",row[1],row[2],variable1);
          printf("--------------------------------------------------------------\n");
          printf("  Id\t  Product\t\tQuantity (KG)  \n");
          printf("--------------------------------------------------------------\n"); 
          s = row[4]; 
          char *token;
          int a=0;
          token = strtok(s,",");
          while(token != NULL){
            arr[a++] = atoi(token);
            token = strtok(NULL, ",");
          }
          int cnt = 0;
          for(int j=0; j<4; j++){
            if(arr[j] == 0){
              continue;
            }
            else{
              cnt++;
              printf("  %d\t  %s           \t%.2f kg  \n", cnt, product[j], arr[j]);
              printf("--------------------------------------------------------------\n");
            }      
          }
          printf("  Total Weight %s \t\tTotal amount    %s\n", row[6], row[5]);
          printf("--------------------------------------------------------------\n");
          //printf("                   \t\tTotal Weight   %s gm\n", row[6]);
          //printf("--------------------------------------------------------------\n");
          printf("\n");
        } 
        printf("Enter 0 to menu");
        while(a != 5){
          int num = a;
          printf("\nEnter finished order no. :");
          scanf("%d",&cust);
          result = order5();
          while((row = mysql_fetch_row(result))){
              char *s = row[0];
              int variable;
              sscanf(s, "%d", &variable);
              if(variable == cust){
                done(cust);
                a += 1;
              }
          }
          if(num == a){
            printf("Invalid Input\n");
          }
          if(cust == 0){
            goto start;
          }
        }
        goto start;
      }
    case 2:
      {
        printf("\n");
        int a=0;
        int cust;
        result = order5t();
        char *test1[4]= {"Wraps","Fries","Beveranges","Sandwich"};
        num_fields = mysql_num_fields(result);
        while ((row = mysql_fetch_row(result)))
        {
          char *s = row[0];
          int variable;
          sscanf(s, "%d", &variable);
          printf("  Cust Id: %d\n",variable);
          printf("--------------------------------------------------------------\n");
          s = row[3];
          long int variable1;
          sscanf(s, "%ld", &variable1);
          printf("  Name:%s %s             Contact No: %ld              \n",row[1],row[2],variable1);
          printf("--------------------------------------------------------------\n");
          printf("  Id\t  Product\t\tQuantity (KG)  \n");
          printf("--------------------------------------------------------------\n"); 
          s = row[4]; 
          char *token;
          int a=0;
          token = strtok(s,",");
          while(token != NULL){
            arr[a++] = atoi(token);
            token = strtok(NULL, ",");
          }
          int cnt = 0;
          for(int j=0; j<4; j++){
            if(arr[j] == 0){
              continue;
            }
            else{
              cnt++;
              printf("  %d\t  %s           \t%.2f kg  \n", cnt, product[j], arr[j]);
              printf("--------------------------------------------------------------\n");
            }      
          }
          printf("  Total Weight %s \t\tTotal amount    %s\n", row[6], row[5]);
          printf("--------------------------------------------------------------\n");
          //printf("                   \t\tTotal Weight   %s gm\n", row[6]);
          //printf("--------------------------------------------------------------\n");
          printf("\n");
        }
        
        printf("Enter 0 to menu");
        while(a != 5){
          int num = a;
          printf("\nEnter finished order no. :");
          scanf("%d",&cust);
          result = order5t();
          while((row = mysql_fetch_row(result))){
              char *s = row[0];
              int variable;
              sscanf(s, "%d", &variable);
              if(variable == cust){
                done(cust);
                a += 1;
              }
          }
          if(num == a){
            printf("Invalid Input\n");
          }
          if(cust == 0){
            goto start;
          }
        }
        goto start;
      }
    case 3:
      {
        int a = 0;
        int cust;
        void printarray(struct customer *array, int n){
          for(int i=0;i<n;i++){
            printf("\nCust_id : %d",array[i].id);
            printf("\nFirstname : %s ",array[i].firstname);
            printf("\nLastname : %s ",array[i].lastname);
            printf("\nContact No : %ld ",array[i].contactNo);
            printf("\nBill : %d",array[i].amt);
            printf("\n");
          }
          printf("\n\n");
        }

        int quickSort1(struct customer *arr, int low, int high)
        {
          int i = low, j = high;
          struct customer temp;
          int mid = (low + high) / 2;
          struct customer pivot = arr[mid];
          while (i <= j)
          {
            while (arr[i].amt > pivot.amt)
              i++;
            while (arr[j].amt < pivot.amt)
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
              if (low < j)
                quickSort1(arr, low, j);
              if (i < high)
                quickSort1(arr, i, high);
          return 0;
        }
        struct customer *arr;
        arr = getdata();
          
        quickSort1(arr,0,field-1);
        printf("%d\n",field);
        for(int i=0; i<field; i++){
          printf("  Cust No : %d \t\t\t\n",arr[i].id);
          printf("--------------------------------------------------------------\n");
          printf("  Name:%s %s             Contact No: %ld              \n",arr[i].firstname,arr[i].lastname,arr[i].contactNo);
          printf("--------------------------------------------------------------\n");
          printf("  Id\t  Product\t\tQuantity (KG)  \n");
          printf("--------------------------------------------------------------\n"); 
          int cnt = 0;
          for(int j=0; j<4; j++){
            if(arr[i].order[j] == 0){
              continue;
            }
            else{
              cnt++;
              printf("  %d\t  %s           \t%.2f kg  \n", cnt, product[j], arr[i].order[j]);
              printf("--------------------------------------------------------------\n");
            }      
          }
          printf("  Total Weight %d \t\tTotal amount    %.2f\n", arr[i].weight, arr[i].amt);
          printf("--------------------------------------------------------------\n");
          //printf("                   \t\tTotal Weight   %s gm\n", row[6]);
          printf("\n\n");
        }
        printf("\n");
        //printarray(a, field);
        printf("Enter 0 to menu");
        while(a != field){
          int num = a;
          struct customer *result;
          printf("\nEnter finished order no. :");
          scanf("%d",&cust);
          result = getdata();
          for(int i=0; i<field; i++){
            if(result[i].id == cust){
              done(cust);
              a = a+1;
            }
          }

          if(num == a){
            printf("Invalid Input\n");
          }
          if(cust == 0){
            goto start;
          }

        }
        goto start;
      }
    case 4:
      {
        int a = 0;
        int cust;
        void printarray(struct customer *array, int n){
          for(int i=0;i<n;i++){
            printf("\nCust_id : %d",array[i].id);
            printf("\nFirstname : %s ",array[i].firstname);
            printf("\nLastname : %s ",array[i].lastname);
            printf("\nContact No : %ld ",array[i].contactNo);
            printf("\nBill : %d",array[i].amt);
            
            printf("\n");
          }
          printf("\n\n");
        }

        int quickSort2(struct customer *arr, int low, int high)
        {
          int i = low, j = high;
          struct customer temp;
          int mid = (low + high) / 2;
          struct customer pivot = arr[mid];
          while (i <= j)
          {
            while (arr[i].wt < pivot.wt)
              i++;
            while (arr[j].wt > pivot.wt)
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
              if (low < j)
                quickSort2(arr, low, j);
              if (i < high)
                quickSort2(arr, i, high);
          return 0;
        }
        struct customer *new;
        new = getdata();
          
        quickSort2(new,0,field-1);
        printf("%d\n",field);
        for(int i=0; i<field; i++){ 
          printf("  Cust No : %d \t\t\tTime : %d\n",new[i].id,new[i].wt);
          printf("--------------------------------------------------------------\n");
          printf("  Name:%s %s             Contact No: %ld              \n",new[i].firstname,new[i].lastname,new[i].contactNo);
          printf("--------------------------------------------------------------\n");
          printf("  Id\t  Product\t\tQuantity (KG)  \n");
          printf("--------------------------------------------------------------\n"); 
          int cnt = 0;
          for(int j=0; j<4; j++){
            if(new[i].order[j] == 0){
              continue;
            }
            else{
              cnt++;
              printf("  %d\t  %s           \t%.2f kg  \n", cnt, product[j], new[i].order[j]);
              printf("--------------------------------------------------------------\n");
            }      
          }
          printf("  Total Weight %d \t\tTotal amount    %.2f\n", new[i].weight, new[i].amt);
          printf("--------------------------------------------------------------\n");
          //printf("                   \t\tTotal Weight   %s gm\n", row[6]);
          printf("\n\n");
        }
        printf("\n");
        //printarray(a, field);
        printf("Enter 0 to menu");
        while(a != field){
          int num = a;
          struct customer *result;
          printf("\nEnter finished order no. :");
          scanf("%d",&cust);
          result = getdata();
          for(int i=0; i<field; i++){
            if(result[i].id == cust){
              done(cust);
              a = a+1;
            }
          }

          if(num == a){
            printf("Invalid Input\n");
          }
          if(cust == 0){
            goto start;
          }

        }
        goto start;
      }
  }
}

int check(char username[20], char password[20]){
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "khadde",
          "DS", 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
      //finish_with_error(con);
  }

  char buf[1024] = {};
  char query_string[] = {"SELECT * from login where username='%s' && password='%s'"};
  sprintf(buf,query_string,username,password);
  if (mysql_query(con, buf))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }
  
  int num_fields = mysql_num_fields(result);
  int a=0;
  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result)))
  {
    if(strcmp(row[1], username) == 0){
      if(strcmp(row[2], password) == 0){
          mysql_free_result(result);
          mysql_close(con);          
          return 1;
      }
      else{
          mysql_free_result(result);
          mysql_close(con);
          return 0;
      }
    }
  }
}

MYSQL_RES *order5(){
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "khadde",
          "DS", 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
      //finish_with_error(con);
  }

  char buf[1024] = {};
  char query_string[] = {"SELECT * from customer where status='Pending' ORDER BY cust_no LIMIT 5"};
  sprintf(buf,query_string);
  if (mysql_query(con, buf))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  return result;
}

MYSQL_RES *order5t(){
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "khadde",
          "DS", 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
      //finish_with_error(con);
  }

  char buf[1024] = {};
  char query_string[] = {"SELECT * from customer where status='Pending' ORDER BY time ASC LIMIT 5"};
  sprintf(buf,query_string);
  if (mysql_query(con, buf))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  return result;
}

struct customer *getdata(){

  struct customer *cust = malloc(sizeof(struct customer) * 20);
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "khadde",
          "DS", 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
      //finish_with_error(con);
  }

  char buf[1024] = {};
  char query_string[] = {"SELECT * from customer where status='Pending'"};
  sprintf(buf,query_string);
  if (mysql_query(con, buf))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }



  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }
  int arr[4];
  int a=0;
  MYSQL_ROW row;
  while ((row = mysql_fetch_row(result)))
  {
        char *s = row[0];
        int variable;
        sscanf(s, "%d", &variable);
        cust[a].id = variable;
        cust[a].firstname = row[1];
        cust[a].lastname = row[2];
        s = row[3];
        long int variable1;
        sscanf(s, "%ld", &variable1);
        cust[a].contactNo = variable1;
        s = row[4];
        char *token;
        int d=0;
        token = strtok(s,",");
        while(token != NULL){
          cust[a].order[d++] = atof(token);
          token = strtok(NULL, ",");
        }
        s = row[5];
        float variable2;
        sscanf(s, "%f", &variable2);
        cust[a].amt = variable2;
        s = row[6];
        sscanf(s, "%d", &variable);
        cust[a].weight = variable;
        s = row[7];
        sscanf(s, "%d", &variable);
        cust[a].wt = variable;
      a++;
  }
  field = a;
  return cust;
}

void done(int cust)
{
  //printf("Firstname: %s",c[0].firstname);
  //printf("\nLastname: %s",c[0].lastname);
  //printf("\nPhone No: %ld",c[0].contactNo);
  //printf("\nPrice: %d", c[0].amt);
  //printf("\nWeight: %d", c[0].weight);
  //printf("\ntime: %d",c[0].wt);
  
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "khadde",
          "DS", 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  char buf[1024] = {};
  char query_string[] = {"UPDATE customer SET status='Done' WHERE cust_no='%d'"};
  sprintf(buf, query_string,cust);
  if (mysql_query(con, buf))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
  }
  mysql_close(con);
}


int * idk3(int no){
  static int arr[4];
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "khadde",
          "DS", 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
      //finish_with_error(con);
  }
  
  char buf[1024] = {};
  char query_string[] = {"SELECT * FROM data where cust_id = %d"};
  sprintf(buf, query_string,no);

  if (mysql_query(con, buf))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  int num_fields = mysql_num_fields(result);
  MYSQL_ROW row;
  int a=0;
  while ((row = mysql_fetch_row(result)))
  {
      char *s = row[1];
      char *token;
      
      token = strtok(s,",");
      while(token != NULL){
        arr[a++] = atoi(token);
        token = strtok(NULL, ",");
      }

      /*for(int i = 0; i < num_fields; i++)
      {
          printf("%s ", row[i] ? row[i] : "NULL");
      }*/
      //printf("\n");
  }

  mysql_free_result(result);
  mysql_close(con);
  return arr;
}
