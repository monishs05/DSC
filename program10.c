#include<stdio.h>
#include<stdlib.h>
int n;

void swap(int *a,int *b)
{
 int temp;
 temp=*a;
 *a=*b;
 *b=temp;
}

void heapify(int a[10],int i)
{
  int left,right,largest;
  left=2*i;
  right=2*i+1;
  
  if(left<=n && a[left]>a[i])
       largest=left;
  else
       largest=i;
  
  if(right<=n && a[right]>a[largest])
       largest=right;
  if(largest!=i)
  {
     swap(&a[i],&a[largest]);
     heapify(a,largest);
  }
}

void buildheap(int a[10])
{
  int i;
  for(i=n/2;i>=1;i--)
      heapify(a,i);
}


int extractmax(int a[10])
{
 int max;
 if(n==0)
 {
   printf("Heap is Empty\n");
   return -1;
 }
 else
 {
  max=a[1];
  a[1]=a[n];
  n=n-1;
  heapify(a,1);
  return max;
 }
}

int main()
{
  int a[10],i,ch,del;
  for(;;)
  {
    printf("\n1.Create Heap\n2.Delete\n3.Exit\n");
    printf("Read the choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nRead the number of elements:");
             scanf("%d",&n);
             printf("\nRead elements:\n");
             for(i=1;i<=n;i++)
               scanf("%d",&a[i]);
             buildheap(a);
             printf("Elements after constructing heap\n");
              for(i=1;i<=n;i++)
               printf("%d\t",a[i]);
             break;
    
      case 2:del=extractmax(a);
             if(del!=-1)
                 printf("Element deleted is %d",del);
             printf("\nElements after deletion\n");
             for(i=1;i<=n;i++)
               printf("%d\t",a[i]);
             break;

     default:exit(0);
   }
  }
}

