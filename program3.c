#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

struct queue
{
 int f,r;
 char data[SIZE][25];
};
typedef struct queue QUEUE;

void enqueue(QUEUE *cq,char item[25])
{
 if(cq->f==(cq->r+1)%SIZE)
       printf("\nQueue is full");
 else
 {
      cq->r=(cq->r+1)%SIZE;
      strcpy(cq->data[cq->r],item);
    
      if(cq->f==-1)
             cq->f=cq->f+1;
 }
}

char* dequeue(QUEUE *cq)
{
  char *d;
  if(cq->f==-1)
  {
    printf("\nQueue is empty");
    return NULL;
  }
  else
  {
    d=cq->data[cq->f];
    if(cq->f==cq->r)
    {
         cq->f=-1;
         cq->r=-1;
    }
    else
         cq->f=(cq->f+1)%SIZE;
    return d;
  }
}


void display(QUEUE cq)
{
  int i;
  if(cq.f==-1)
       printf("\nQueue is Empty");
  
  else if(cq.r>=cq.f)
  {
       printf("\nQueue content are:\n");
       for(i=cq.f;i<=cq.r;i++)
              printf("%s\n",cq.data[i]);
  }

  else
  {
       printf("\nQueue content are:\n");
       for(i=cq.f;i<SIZE;i++)
               printf("%s\n",cq.data[i]);
       for(i=0;i<=cq.r;i++)
               printf("%s\n",cq.data[i]);
  }
}

int main()
{
   int ch;
   char item[25];
   char *d;
   QUEUE cq;
   cq.f=-1;
   cq.r=-1;
   for(;;)
   {
       printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\nRead choice:\n");
       scanf("%d",&ch);
       getchar();       
       switch(ch)
       {
          case 1:printf("\nEnter message to be sent\n");
                 gets(item);
                 enqueue(&cq,item);
                 break;
           
          case 2:d=dequeue(&cq);
                 if(d!=NULL)
                     printf("Message retrived is %s\n",d);
                 break;
    
          case 3:display(cq);
                 break;

         default:exit(0);
        }
    }
} 

 

