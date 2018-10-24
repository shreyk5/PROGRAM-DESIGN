#include<stdio.h>
#include<stdlib.h>

struct node 
{
   int data;
   struct node *left;
   struct node *right;
   struct node *p;  // parent node
};

struct node* constructTree(int idx,int *a,int n)
{
   struct node *temp=NULL;

   if(idx<n)
   { 
       temp=(struct node*)malloc(sizeof(struct node));
       temp->data=a[idx];
       temp->left=(struct node*)malloc(sizeof(struct node));
       temp->left=constructTree(2*idx+1,a,n);
       if(temp->left!=NULL)temp->left->p=temp;
      
       temp->right=(struct node*)malloc(sizeof(struct node));
       temp->right=constructTree(2*idx+2,a,n);    
       if(temp->right!=NULL) temp->right->p=temp;
   }

  return temp;
}

void preorder(struct node *root)
{
   if(root!=NULL)
   {
     printf("%d ",root->data);
     preorder(root->left);
     preorder(root->right);
   }
}

void inorder(struct node *root ) {

    if (root != NULL) {

        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    
}

void postorder(struct node *root)
{
   if(root!=NULL)
   {
     postorder(root->left);
     postorder(root->right);
     printf("%d ",root->data);
   }
}

int main()
{
  int n;
  scanf("%d",&n);

  int a[n];
  for(int i=0;i<n;i++) scanf("%d",&a[i]);

  struct node *root=(struct node*)malloc(sizeof(struct node));
  
  root=constructTree(0,a,n);
  
  printf("Preorder traversal :");  
  preorder(root);
  printf("\nInorder traversal :");
  inorder(root);
  printf("\nPostorder traversal :");
  postorder(root);
}