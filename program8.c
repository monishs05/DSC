#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
 char data;
 struct node *left;
 struct node *right;
};
typedef struct node *NODE;


NODE createnode(char item)
{
 NODE temp;
 temp=(NODE)malloc(sizeof(struct node));
 temp->data=item;
 temp->left=NULL;
 temp->right=NULL;
 return temp;
}

int preceed(char c)
{
  switch(c)
  {
    case '$':return 5;
    case '*':
    case '/':return 3;
    case '+':
    case '-':return 1;
  }
}

NODE createEXPtree(char infix[15])
{
  NODE t,l,r;
  NODE treestack[20],operatorstack[20],temp;
  int top1=-1,top2=-1,i;
  char symbol;
  for(i=0;infix[i]!='\0';i++)
  {
     symbol=infix[i];
     if(isalnum(symbol))
     {
        temp=createnode(symbol);
        treestack[++top1]=temp;
     } 
     else
     {
        temp=createnode(symbol);
        if(top2==-1)
             operatorstack[++top2]=temp;
        else
        {
           while((preceed(symbol)<=preceed(operatorstack[top2]->data))&&top2!=-1)
           {
                t=operatorstack[top2--];
                r=treestack[top1--];
                l=treestack[top1--];
                t->right=r;
                t->left=l;
                treestack[++top1]=t;
           }
       operatorstack[++top2]=temp;
           }
         
      }
   }
   while(top2!=-1)
   {
       t=operatorstack[top2--];
       r=treestack[top1--];
       l=treestack[top1--];
       t->right=r;
       t->left=l;
       treestack[++top1]=t;
   }
   return treestack[top1];
}

void preorder(NODE root)
{
 if(root!=NULL)
 {
   printf("%c\t",root->data);
   preorder(root->left);
   preorder(root->right);
 }
}

void inorder(NODE root)
{
 if(root!=NULL)
 {
    inorder(root->left);
    printf("%c\t",root->data);
    inorder(root->right);
 }
}

void postorder(NODE root)
{
 if(root!=NULL)
 {
   postorder(root->left);
   postorder(root->right);
   printf("%c\t",root->data);
 }
 
}
int main()
{
  NODE root=NULL;
  char infix[20];
  printf("\nRead the expression\n");
  scanf("%s",infix);
  root=createEXPtree(infix);

  printf("\nPreorder traversal is\n");
  preorder(root);

  printf("\nInorder traversal is\n");
  inorder(root);

  printf("\nPostorder traversal is\n");
  postorder(root);
  
  printf("\n");
  return 0;
}



