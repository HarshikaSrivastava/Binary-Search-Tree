#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>

typedef struct bstree
{
struct bstree *left;
int info;
struct bstree *right;
}BST;

void main()
{
 BST *root;
 root=NULL;
 void inordertraversal(BST*);
 void insertelement(BST**,int);
 int item;
 int  choice;
 clrscr();

 while(1)
 {
   clrscr();
   printf("MENU");
   printf("\n 1. insert element");
   printf("\n 2. traverse inorder ");
   printf("\n 3. exit");
   printf("\nEnter your choice");
   scanf("%d",&choice);
   switch(choice)
   {
	case 1 : printf("\nEnter the item to insert ");
		 scanf("%d",&item);
		 insertelement(&root,item);
		 clrscr();
		 printf("\n item inserted successfully");
		 getch();
		 break;

	case 2 :  inordertraversal(root);
		   getch();
		   break;

	case 3 : exit(1);


	default : printf("\n wrong choice try again");

   }

 }

 getch();
}

void insertelement(BST **tree,int item)
{
 BST *ptr,*nodeptr,*pptr;
 ptr=(BST*)malloc(sizeof(BST));
 ptr->info=item;
 ptr->left=NULL;
 ptr->right=NULL;
 if(*tree==NULL)
  *tree=ptr;
 else
   {  nodeptr=*tree;
      pptr=NULL;

 while(nodeptr!=NULL)
 {
  ptr=nodeptr;
  if(item<nodeptr->info)
      nodeptr=nodeptr->left;
  else
      nodeptr=nodeptr->right;
  }
  if(item<pptr->info)
    pptr->left=ptr;
  else
    pptr->right=ptr;

    }
 }


void inordertraversal(BST *tree)
{
     if(tree != NULL)
      {
	  inordertraversal(tree->left);
	  printf("%d",(tree->info));
	  inordertraversal(tree->right);
      }
}