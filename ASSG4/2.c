#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int value;
	struct node *left, *right, *parent;
}*root;

void insert(struct node **tree, int element);
void search(struct node *tree, int key);
void findMin(struct node *tree);
void findMax(struct node *tree);
void predecessor(struct node *tree, int element);
void successor(struct node *tree, int element);
void delete(struct node **tree, int element);
void inorder(struct node *tree);
void preorder(struct node *tree);
void postorder(struct node *tree);

int main()
{
	insert(&root, 5);
	insert(&root, 4);
	insert(&root, 2);
	insert(&root, 3);
	insert(&root, 9);
	insert(&root, 10);
	insert(&root, 7);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	return 0;
}

void insert(struct node **tree, int element)
{
	struct node *ele = malloc(sizeof(struct node));
	ele->value = element;
	ele->left = NULL;
	ele->right = NULL;
	ele->parent = NULL;
	if((*tree) == NULL)
	{
		(*tree) = ele;
	}
	else
	{
		struct node *temp;
		temp = *tree;
		while(1)
		{
			if(element > temp->value)
			{
				if(temp->right == NULL)
				{
					temp->right = ele;
					ele->parent = temp;
					break;
				}
				else
				{
					temp = temp->right;
				}
			}
			else
			{
				if(temp->left == NULL)
				{
					temp->left = ele;
					ele->parent = temp;
					break;
				}
				else
				{
					temp = temp->left;
				}
			}
		}
	}
}

void search(struct node *tree, int key)
{
	struct node *temp;
	temp = tree;
	if(temp == NULL)
		printf("NOT FOUND\n");
	else if(temp->value == key)
		printf("FOUND\n");
	else if(key > temp->value)
		search(temp->right, key);
	else
		search(temp->left, key);
}

void findMin(struct node *tree)
{
	struct node *temp;
	temp = tree;
	if(temp == NULL)
		printf("NIL\n");
	else
	{
		while(temp->left != NULL)
			temp = temp->left;
		printf("%d\n", temp->value);
	}
}

void findMax(struct node *tree)
{
	struct node *temp;
	temp = tree;
	if(temp == NULL)
		printf("NIL\n");
	else
	{
		while(temp->right != NULL)
			temp = temp->right;
		printf("%d\n", temp->value);
	}
}

void inorder(struct node *tree)
{
	if(tree != NULL)
	{
		inorder(tree->left);
		printf("%d ", tree->value);
		inorder(tree->right);
	}
}

void preorder(struct node *tree)
{
	if(tree != NULL)
	{
		printf("%d ", tree->value);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void postorder(struct node *tree)
{
	if(tree != NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d ", tree->value);
	}
}