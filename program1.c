#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct stack
{
 int data[SIZE];
 int top;
};
typedef struct stack STACK;

void push(STACK *s,int item)
{
 if(s->top==SIZE-1)
   	printf("\nStack Overflow");
 else
 {
  	s->top=s->top+1;
        s->data[s->top]=item;
 }

}

int pop(STACK *s)
{
	if(s->top==-1)
        {
 	  printf("\nStack Underflow");
          return -1;
        }
 	else
   	{
	  return s->data[(s->top)--];
        }
}

void display(STACK *s)
{
 	int i;
	if(s->top==-1)
 	 	printf("\nStack is empty");
        else
        {
          	printf("\nStack content are:\n");
                for(i=s->top;i>=0;i--)
                    printf("%d\n",s->data[i]);
        }
}

void popn(STACK *s,int n)
{
        int i,noe;
        noe=(s->top)+1;
  	if(n>noe)
             printf("Can't pop as there are less elements\n");
        else
        {
           printf("Elements popped are\n");
           for(i=1;i<=n;i++)
           {
            printf("%d\n",pop(s));
           }
        }
}

void bottom3(STACK *s)
{
 STACK s1;
 int i,x;
 s1.top=-1;
 int noe = s->top+1;

 if(noe < 3)
   printf("Less no of elements in stack");
 else
 {
   for(i=s->top;i>=3;i--)
       push(&s1,pop(s));

   x=s->data[s->top];

   printf("\nBottom 3rd element is %d",x);

   while(s1.top!=-1)
         push(s,pop(&s1));
 }
}
void top3(STACK *s)
{
 STACK s1;
 int i,y;
 s1.top=-1;
 int noe = s->top+1;

 if(noe<3)
   printf("\nLess no of elements in stack");
 else
 {
   push(&s1,pop(s));     
   push(&s1,pop(s));

   y=s->data[s->top];

   printf("\nTop 3rd element is %d",y);

   while(s1.top!=-1)
         push(s,pop(&s1));
 }
}

/*void bthird(STACK *s)
{
  STACK ts;
  int i,x;
  
  //ts.top=-1;
  for(i=0;i<=3;i++)
  {
    x=pop(s);
    push(&ts,x);
  }
  printf("Third element from the bottom is %d\n",s->data[s->top]);
  for(i=0;i<=3;i++)
  {
    x=pop(&ts);
    push(s,x);
  }
}

void tthird(STACK *s)
{
 STACK ts;
 int i,x;

 ts.top=-1;
 for(i=0;i<3;i++)
 {
  x=pop(&ts);
  push(s,x);
 }
 printf("Third element from the top is %d\n",s->top);
 for(i=0;i<3;i++)
 {
  x=pop(&ts);
  push(s,x);
 }
}

*/


int main()
{
 int ch,item,d,n;
 STACK s;
 s.top=-1;
 for(;;)
 {
 	printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.POP n ELEMENTS\n5.DISPLAY BOTTOM 3RD ELEMENT\n6.DISPLAY TOP 3RD ELEMENT\n7.EXIT\nRead choice\n");
        scanf("%d",&ch);

 	switch(ch)
	{
	  case 1:printf("\nEnter the element to be pushed:");
                 scanf("%d",&item);
 		 push(&s,item);
 		 break;
	  case 2:d=pop(&s);
		 if(d!=-1)
		     printf("\nElement popped is %d\n",d);
                 break;
 	  case 3:display(&s);
                 break;
	  case 4:printf("Enter the no of elements to be popped\n");
                 scanf("%d",&n);
                 popn(&s,n);
                 break; 
          case 5:bottom3(&s);
                 break;
          case 6:top3(&s);
                 break;
         default:exit(0);
        }
 }

}		
