#include<stdio.h>
#include<mysql/mysql.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX_LEN 10
char empty[]="";

struct customer
{
    char firstname[20];
    char lastname[20];
    long int contactNo;
    float amt;
    int weight;
    int wt;
    float order[4];
};

int que[50];
void details(struct customer []);                          //function to get details of customer
void displayQueue(struct customer [], int);                 //function to display queue
void addq(struct customer c[],int k);                      //function to add to the queue
int delq (struct customer c[], int k, int);                 	//function to delete the queue
void cancel(struct customer c[], int tempno, int l);
void query(struct customer c[], char str[MAX_LEN]);
void display();
int i=0;                                                    
int twt=0;                                                  
int rear = -1;
int frnt = -1;

char str[MAX_LEN];
int cust_id(struct customer c[]);

int main()
{
    int choice;
    char ch;
    float amount;
    struct customer c[50];
    //int order[4] = {0,0,0,0}; 
    start: printf("Welcome! \nEnter your personal details \n");
    details(c);
    c[i].amt=0;
    c[i].wt=0;
    c[i].weight=0;
    int cnt = 1;
    for(int j=0;j<4;j++){
      c[i].order[j] = 0;
    }
    char *product[4]= {"Wheat","Rice","Olive Oil","Sugar"};
    printf("\nPlace your order\n");
    printf("MENU: \n\t 0. Cancel Order\n\t 1. Wheat \n\t 2. Rice \n\t 3. Olive oil \n\t 4. Sugar \n\t 5. End Order\n\n");
    s: printf("Enter your order number: ");
       scanf("%d", &choice); 

    switch(choice)
    {
        case 1:
        {
            printf("Enter quantity (in kg): ");
            scanf("%f",&amount);
            c[i].order[0] += amount;
            c[i].amt=c[i].amt+30*amount;
            c[i].weight=c[i].weight+amount*1000;
            amount = round(amount);
            c[i].wt=c[i].wt+20*amount;
            goto s;
            break;
        }
        case 2:
        {
            printf("Enter quantity (in kg): ");
            scanf("%f",&amount);
            c[i].order[1] += amount;
            c[i].amt=c[i].amt+30*amount;
            c[i].weight=c[i].weight+amount*1000;
            amount = round(amount);
            c[i].wt=c[i].wt+20*amount;
            goto s;
            break;
        }
        case 3:
        {
            printf("Enter quantity (in kg): ");
            scanf("%f",&amount);
            c[i].order[2] += amount;
            c[i].amt=c[i].amt+20*amount;
            c[i].weight=c[i].weight+amount*1000;
            amount = round(amount);
            c[i].wt=c[i].wt+5*amount;
            goto s;
            break;
        }
        case 4:
        {
            printf("Enter quantity (in kg): ");
            scanf("%f",&amount);
            c[i].order[3] += amount;
            c[i].amt=c[i].amt+50*amount;
            c[i].weight=c[i].weight+amount*1000;
            amount = round(amount);
            c[i].wt=c[i].wt+40*amount;
            goto s;
            break;
        }
        case 5:
        {
            printf("Order ended successfully\n");
            break;      
        }
        case 0:
        {
            int tempno=0;
            printf("Enter mobile no.: ");
            scanf("%d", &tempno);
            cancel(c,tempno,i);
            goto start;
        }break;
        default:
        printf("Invalid input\n");
        goto s;
    }
    
    printf("\n\t    **** GROCERY STORE BILL ****\n");
    printf("--------------------------------------------------------------\n");
    printf("Name:%s %s                       Contact No: %ld              \n",c[i].firstname,c[i].lastname,c[i].contactNo);
    printf("--------------------------------------------------------------\n");
    printf("  Id\t  Product\t\tQuantity (KG)\t\tPrice  \n");
    printf("--------------------------------------------------------------\n");
    for(int j=0; j<4; j++){
      if(c[i].order[j] == 0){
        continue;
      }
      else{
        printf("  %d\t  %s           \t%.2f kg  \t\t%.2f  \n", cnt, product[j], c[i].order[j], c[i].amt);
        printf("--------------------------------------------------------------\n");
        cnt++;
      }      
    }
    printf("  Total product %d \t\tTotal amount    %.2f\n", cnt, c[i].amt);
    printf("--------------------------------------------------------------\n");
    printf("                   \t\tTotal Weight   %d\n", c[i].weight);
    printf("--------------------------------------------------------------\n");

    /*printf("\nYour amount is: Rs %.2f ", c[i].amt);
    printf("\nYour bag weight is: %d gm", c[i].weight);
    printf("\nYour waiting time is: Sec  %d ", c[i].wt);*/
    
    str[0] = '\0';
        for (int j = 0; j < 4; j++)
        {
            char temp[MAX_LEN];
            sprintf(temp, "%.2f,", c[i].order[j]);
            strcat(str, temp);
        }
    str[strlen(str) - 1] = '\0';
    twt +=c[i].wt;
    addq(&c[0],i);
    query(&c[i],str);
    delq(&c[0],i, twt);
    display();
    printf("Do you want to enter again? (Y/N): ");
    scanf("%s",&ch);
    if(ch=='y' || ch=='Y' || ch==' ')
    {
      i++;
      goto start;
    }
    else{
      exit(0);
    }
}

void details(struct customer c[50])
{
    printf("\n");
    printf("Enter your Firstname: ");
    scanf("%s", c[i].firstname);
    printf("Enter your Lastname: ");
    scanf("%s", c[i].lastname);
    //printf("%s", c[i].name);
    printf("Enter your contact number: ");
    scanf("%ld", &c[i].contactNo);
}

void displayQueue(struct customer c[], int l)
{
    int j;
    printf("\n \n");
    printf("\nThe waiting queue is: \n");
    display();
    for (j=frnt; j<l; j++)
    {
      printf("%s %s",c[j].firstname, c[j].lastname);
      //puts(c[j].firstname,c[j].lastname);
      printf("\n");
    }
    printf("\n \n \n");
}

void cancel(struct customer c[],int no, int l)
{
    int j;
    for(j=frnt;j<l;j++)
    {
        if(c[j].contactNo==no)
       {
	strcpy(c[j].firstname,empty);
  strcpy(c[j].lastname, empty);
            c[j].amt=0;
            c[j].wt=0;
            c[j].contactNo=0;
            break;
        }
    }
  displayQueue(&c[0], l);
}
void addq(struct customer c[], int k)
{
    if (frnt == -1)
    {
        frnt = 0;
    }
    rear = rear+1;
    if (c[k].wt < c[k+1].wt)
    {
        que[rear] = k;
    }
    else
    {
        que[rear] = k+1;
    }
    //displayQueue(&c[0], k);
    //displayq(&c[0], k);
}

int delq (struct customer c[], int k, int total_wt)
{
    //int itm;
    //printf("%d twt", total_wt);
    if (total_wt > 50)
    {
        //itm = que[frnt];
        frnt = frnt+1;
        //displayQueue(&c[0],k );
        twt= c[i].wt;
    }
    return 0;
}

void query(struct customer c[], char str[MAX_LEN])
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
  char query_string[] = {"INSERT INTO customer(firstname, lastname, phone_no, orders, bill, weight, time, status) VALUES('%s','%s',%ld,'%s',%.2f,%d,%d,'Pending')"};
  sprintf(buf, query_string,c[i].firstname,c[i].lastname,c[i].contactNo,str,c[i].amt,c[i].weight,c[i].wt);

  if (mysql_query(con, buf))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
  }
  mysql_close(con);
}

/*int cust_id(struct customer c[]){
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
  char query_string[] = {"SELECT cust_no from Orders where firstname='%s' && lastname='%s' && phone_no=%ld && bill=%d && weight=%d && time=%d && status='Pending' ORDER BY cust_no DESC LIMIT 1"};
  sprintf(buf, query_string,c[i].firstname,c[i].lastname,c[i].contactNo,c[i].amt,c[i].weight,c[i].wt );
  
  if (mysql_query(con, buf))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
  }

  MYSQL_RES *result = mysql_store_result(con);
  MYSQL_ROW row = mysql_fetch_row(result);
  int num_fields = mysql_num_fields(result);
  char *s = row[0];
  int cust_di;
  sscanf(s, "%d", &cust_di);
  //  printf("%s ",row[0]);

  mysql_close(con);
  return cust_di;
}*/

void display(){
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

  if (mysql_query(con, "SELECT * FROM customer WHERE status='Pending'"))
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
  int sec = 0;
  int variable;
  while ((row = mysql_fetch_row(result)))
  {
      a += 1;
      for(int i = 1; i < 3; i++)
      {
          //printf("%s ", row[i] ? row[i] : "NULL");
          char *s = row[7];
          sscanf(s, "%d", &variable);
      }
      sec = sec + variable;
  }

  sec = round(sec/60);
  printf("  Waiting No %d \t\tWaiting time: %d min\n", a, sec);
  printf("--------------------------------------------------------------\n");
  printf("\n"); 
  //printf("\nYour waiting no. is: %d",a);
  //printf("\nYour waiting time is: %d min\n\n",sec);
  mysql_free_result(result);
  mysql_close(con);
}

