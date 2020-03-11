#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int h[SIZE];

void insert()
{
 int key,index,i,hkey,flag=0;
 printf("\nEnter a value to insert into hash table\n");
 scanf("%d",&key);
 hkey=key%SIZE;
 for(i=0;i<SIZE;i++)
 {
   index=(hkey+i)%SIZE;
   if(h[index]==0)
   {
     h[index]=key;
     break;
   }
 }
 if(i==SIZE)
    printf("\nElement cannot be inserted\n");
}

void delete()
{
 int key,index,i,flag=0,hkey;
 printf("\nEnter search element\n");
 scanf("%d",&key);
 hkey=key%SIZE;
 for(i=0;i<SIZE;i++)
 {
    index=(hkey+i)%SIZE;
    if(h[index]==key)
    {
      h[index]=0;
      printf("Value is found at index %d",index);
      flag=1;
      break;
    }
 }
 if(flag==0)
     printf("\nValue is not found\n");
}


void display()
{
  int i;
  printf("\nElements in the hash table are\n");
  for(i=0;i<SIZE;i++)
      printf("\nAt index %d\t value = %d",i,h[i]);
}

int main()
{
  int opt,i;
  for(;;)
  {
   printf("\n1.INSERT\n2.DISPLAY\n3.SEARCH\n4.EXIT\n");
   scanf("%d",&opt);

   switch(opt)
   {
     case 1:insert();
            break;
     case 2:display();
            break;
     case 3:delete();
            break;
    default:exit(0);
  }
 }
}

