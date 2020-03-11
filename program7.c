#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *left;
 struct node *right;
};
typedef struct node *NODE;

NODE createBST(NODE root,int item)
{
 NODE temp,cur,prev;
 temp=(NODE)malloc(sizeof(struct node));
 temp->data=item;
 temp->left=NULL;
 temp->right=NULL;
 
 if(root==NULL)
          return temp;

 cur=root;
 prev=NULL;
 
 while(cur!=NULL)
 {
   prev=cur;
   if(item<cur->data)
        cur=cur->left;
   else
        cur=cur->right;
 }
 if(prev->data>item)
          prev->left=temp;
 else
          prev->right=temp;
 return root;
}

void preorder(NODE root)
{
 if(root!=NULL)
 {
   printf("%d\t",root->data);
   preorder(root->left);
   preorder(root->right);
 }
}

void inorder(NODE root)
{
 if(root!=NULL)
 {
  inorder(root->left);
  printf("%d\t",root->data);
  inorder(root->right);
 }
}

void postorder(NODE root)
{
 if(root!=NULL)
 {
  postorder(root->left);
  postorder(root->right);
  printf("%d\t",root->data);
 }
}

NODE inordersuccessor(NODE root)
{
 NODE cur=root;
 while(cur->left!=NULL)
    cur=cur->left;
 return cur;
}

NODE delete(NODE root,int key)
{
 NODE temp;
 if(root==NULL)
    return root;
 if(key<root->data)
     root->left=delete(root->left,key);
 else if(key>root->data)
      root->right=delete(root->right,key);

 else
 {
   if(root->left==NULL)
   {
      temp=root->right;
      free(root);
      return temp;
   }
   else if(root->right==NULL)
   {
      temp=root->left;
      free(root);
      return temp;
   }
   else
   {
     temp=inordersuccessor(root->right);
     root->data=temp->data;
     root->right=delete(root->right,temp->data);
   }
 }
 return root;
}


int main()
{
  NODE root=NULL;
  int item,key,ch;
  for(;;)
  {
     printf("\n1.INSERT\n2.DELETE\n3.PREORDER\n4.INORDER\n5.POSTORDER\n6.EXIT\nRead choice:\n");
     scanf("%d",&ch);

     switch(ch)
     {
        case 1:printf("Enter element to be inserted\n");
               scanf("%d",&item);
               root=createBST(root,item);
               break;

        case 2:printf("Enter the node to be deleted\n");
               scanf("%d",&key);
               root=delete(root,key);
               break;
           
        case 3:printf("Preorder traversal is\n");
               preorder(root);
               break;

        case 4:printf("Inorder traversal is\n");
               inorder(root);
               break;
 
        case 5:printf("Postorder traversal is\n");
               postorder(root);
               break;
  
       default:exit(0);
      }
  }
}
