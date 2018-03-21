#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *right;
	struct node *left;
	struct node *parent;
};
struct node *tree=NULL;
int i,n,j=0;

struct node* create_newnode(int value);
int search(int ar[],int in_strt,int in_end,int value);
struct node* buildTree(int b[],int a[],int inStrt,int inEnd);
void printBT(struct node *temp);

int main()
{
	scanf("%d",&n);
	int b[n],a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	tree=buildTree(b,a,0,n-1);
	printBT(tree);
	return 0;
}

struct node* create_newnode(int value)
{
	struct node* New=(struct node*)malloc(sizeof(struct node));
	New->value=value;
	New->left=NULL;
	New->right=NULL;
	return New;
}

int search(int ar[],int in_strt,int in_end,int value)
{
	for(i=in_strt;i<=in_end;i++)
	{
		if(ar[i]==value)
			return i;
	}
}

struct node* buildTree(int b[],int a[],int inStrt,int inEnd)
{
	if(inStrt>inEnd)
		return NULL;
	struct node *prev=create_newnode(a[j++]);
	if(inStrt==inEnd)
		return prev;
	int in_index=search(b,inStrt,inEnd,prev->value);
	prev->left=buildTree(b,a,inStrt,in_index-1);
	prev->right=buildTree(b,a,in_index+1,inEnd);
	return prev;
}

void printBT(struct node *temp)
{
	if(temp==NULL)
	{
		printf("( )");
		return;
	}
	printf("( %d ",temp->value);
	printBT(temp->left);
	printf(" ");
	printBT(temp->right);
	printf(" )");
}