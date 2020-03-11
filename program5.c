#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *addr;
};
typedef struct node *NODE;

NODE insertbegin(NODE head,int item)
{
 NODE temp;
 temp=(NODE)malloc(sizeof(struct node));
 temp->data=item;
 if(head->addr==head)
 {
    head->addr=temp;
    temp->addr=head;
    return head;
 }
 else
 {
    temp->addr=head->addr;
    head->addr=temp;
    return head;
 }
}

NODE insertend(NODE head,int item)
{
  NODE temp,cur;
  temp=(NODE)malloc(sizeof(struct node));
  temp->data=item;
  if(head->addr==head)
  {
     head->addr=temp;
     temp->addr=head;
     return head;
  }
 else
 {
    cur=head->addr;
    while(cur->addr!=head)
        cur=cur->addr;
    cur->addr=temp;
    temp->addr=head;
    return head;
 }
}

void display(NODE head)
{
 NODE temp;
 if(head->addr==head)
    printf("\nList empty");
 else
 {
    //printf("\nList contents are\n");
    temp=head->addr;

    while(temp->addr!=head)
    {
        printf("%d",temp->data);
        temp=temp->addr;
    }
    printf("%d\n",temp->data);
 }
}

void addzeroes(NODE head1,NODE head2)
{
 int ct1=1,ct2=1,i;
 NODE cur;
 cur=head1->addr;
 while(cur->addr!=head1)
 {
   ct1=ct1+1;
   cur=cur->addr;
 }
 cur=head2->addr;
 while(cur->addr!=head2)
 {
   ct2=ct2+1;
   cur=cur->addr;
 }

 if(ct1>ct2)
 {
   for(i=1;i<=ct1-ct2;i++)
          head2=insertbegin(head2,0);
 }
 else
 {
   for(i=1;i<=ct2-ct1;i++)
          head1=insertbegin(head1,0);
 }
}


NODE reverse(NODE head)
{
  NODE prev,cur,next;
  prev=head;
  cur=head->addr;
  while(cur!=head)
  {
     next=cur->addr;
     cur->addr=prev;
     prev=cur;
     cur=next;
  }
  head->addr=prev;
  return head;
}


void add(NODE head1,NODE head2)
{
 NODE h,cur1,cur2;
 int sum=0,carry=0,x;
 
 h=(NODE)malloc(sizeof(struct node));
 h->addr=h;
 head1=reverse(head1);
 head2=reverse(head2);

 cur1=head1->addr;
 cur2=head2->addr;

 while(cur1!=head1)
 {
    sum=cur1->data+cur2->data+carry;
    x=sum%10;
    carry=sum/10;

    h=insertbegin(h,x);
    cur1=cur1->addr;
    cur2=cur2->addr;
 }
 if(carry>0)
    h=insertbegin(h,carry);
 
 printf("\nThe result is:\n");
 display(h);
}

int main()
{
 NODE head1,head2;
 char first[20],second[20];
 int i;
 head1=(NODE)malloc(sizeof(struct node));
 head2=(NODE)malloc(sizeof(struct node));
 
 head1->addr=head1;
 head2->addr=head2;

 printf("\nRead first number:\n");
 scanf("%s",first);

 for(i=0;first[i]!='\0';i++)
      head1=insertend(head1,first[i]-'0');
 
 printf("\nFirst number is\n");
 display(head1);
 
 printf("\nRead second number:\n");
 scanf("%s",second);

 for(i=0;second[i]!='\0';i++)
      head2=insertend(head2,second[i]-'0');

 printf("\nSecond number is\n");
 display(head2);

 addzeroes(head1,head2);
 add(head1,head2);
 return 0;
}

                                                                                

