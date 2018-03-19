#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
	int value;
	struct node *left, *right, *parent;
}*root, *prev;

void insert(struct node **tree, int element);
void search(struct node *tree, int key);
void findMin(struct node *tree);
void findMax(struct node *tree);
void predecessor(struct node *tree, int element);
void successor(struct node *tree, int element);
void delete(struct node *tree, int element);
void inorder(struct node *tree);
void preorder(struct node *tree);
void postorder(struct node *tree);

int main()
{
	char str[10];
	int ele;
	while(1)
	{
		scanf("%s", str);
		if(strcmp(str, "stop") == 0)
			return 0;
		else if(strcmp(str, "insr") == 0)
		{
			scanf("%d", &ele);
			insert(&root, ele);
		}
		else if(strcmp(str, "srch") == 0)
		{
			scanf("%d", &ele);
			search(root, ele);
		}
		else if(strcmp(str, "minm") == 0)
		{
			findMin(root);
		}
		else if(strcmp(str, "maxm") == 0)
		{
			findMax(root);
		}
		else if(strcmp(str, "pred") == 0)
		{
			scanf("%d", &ele);
			predecessor(root, ele);
		}
		else if(strcmp(str, "succ") == 0)
		{
			scanf("%d", &ele);
			successor(root, ele);
		}
		else if(strcmp(str, "delt") == 0)
		{
			scanf("%d", &ele);
			delete(root, ele);
		}
		else if(strcmp(str, "inor") == 0)
		{
			inorder(root);
			printf("\n");
		}
		else if(strcmp(str, "prer") == 0)
		{
			preorder(root);
			printf("\n");
		}
		else if(strcmp(str, "post") == 0)
		{
			postorder(root);
			printf("\n");
		}
	}
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
// /**
void successor(struct node *tree, int element)
{
	if(tree->value == element)
	{
		if(tree->right == NULL)
		{
			if(tree->parent == NULL)
			{
				printf("NILL\n");
				return;
			}
		}
	}
	while(1)
	{
		if(tree == NULL)
		{
			printf("NOT FOUND\n");
			return;
		}
		if(tree->value == element)
			break;
		else if(element > tree->value)
			tree = tree->right;
		else
			tree = tree->left;
	}
	if(tree->right != NULL)
		findMin(tree->right);
	else
	{
		if(tree->parent->left == tree)
			printf("%d\n", tree->parent->value);
		else
		{
			if(tree->parent == NULL)
			{
				printf("NILL\n");
				return;
			}
			tree = tree->parent;
			while(tree != NULL)
			{
				if(tree->value > element)
				{
					printf("%d\n", tree->value);
					return;
				}
				tree = tree->parent;
			}
			printf("NIL\n");
		}
	}
}
// **/
/**
void successor(struct node *temp, int x)
{
	while((temp != NULL) && (x != (temp->value)))
	{
		if(x < (temp->value))
			temp = temp->left;
		else
			temp = temp->right;
	}
	if(temp == NULL)
	{
		printf("NOT FOUND\n");
		return;
	}
	struct node *t;
	t = root;
	while((t->right) != NULL)
		t = t->right;
	if(t == temp)
	{
		printf("NIL\n");
		return;
	}
	if((temp->right) != NULL)
	{
		findMin(temp->right);
		return;
	}
	struct node *prev;
	prev = temp->parent;
	while((prev != NULL) && (temp == (prev->right)))
	{
		temp = prev;
		prev = prev->parent;
	}
	printf("%d\n", prev->value);
}
**/

void predecessor(struct node *tree, int element)
{
	if(tree->value == element)
	{
		if(tree->left == NULL)
		{
			if(tree->parent == NULL)
			{
				printf("NILL\n");
				return;
			}
		}
	}
	while(1)
	{
		if(tree == NULL)
		{
			printf("NOT FOUND\n");
			return;
		}
		if(tree->value == element)
			break;
		else if(element > tree->value)
			tree = tree->right;
		else
			tree = tree->left;
	}
	if(tree->left != NULL)
		findMax(tree->left);
	else
	{
		if(tree->parent->right == tree)
			printf("%d\n", tree->parent->value);
		else
		{
			if(tree->parent == NULL)
			{
				printf("NULL\n");
				return;
			}
			tree = tree->parent;
			while(tree != NULL)
			{
				if(tree->value < element)
				{
					printf("%d\n", tree->value);
					return;
				}
				tree = tree->parent;
			}
			printf("NIL\n");
		}
	}
}

void TRANSPLANT(struct node *t, struct node *u, struct node *v)
{

	if((u->parent) == NULL)
		root = v;
	else if(u == ((u->parent)->left))
		((u->parent)->left) = v;
	else
		(u->parent)->right = v;
	if(v != NULL)
		v->parent = u->parent;
}
void delete(struct node *temp, int x)
{
	while(x != (temp->value))
	{
		if(x < (temp->value))
			temp = temp->left;
		else
			temp = temp->right;
	}
	if((temp->left) == NULL)
		TRANSPLANT(root, temp, temp->right);
	else if((temp->right) == NULL)
		TRANSPLANT(root, temp, temp->left);
	else
	{
		struct node *t = (temp->right);
		if(t == NULL)
			prev = NULL;
		while((t->left) != NULL)
			t = t->left;
		prev = t;
		if((prev->parent) != temp)
		{
			TRANSPLANT(root, prev, prev->right);
			prev->right = temp->right;
			(prev->right)->parent = prev;
		}
		TRANSPLANT(root, temp, prev);
		prev->left = temp->left;
		(prev->left)->parent = prev;
	}
}
