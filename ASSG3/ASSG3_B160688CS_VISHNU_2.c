#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int value;
	struct node *next;
}*h1, *t1, *h2, *t2;

void insert(struct node **head, struct node **tail, int val)
{
	struct node *new = malloc(sizeof(struct node));
	new->value = val;
	new->next = NULL;
	if((*head) == NULL)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		(*tail) = new;
	}
}

void getTail(struct node **head, struct node **tail)
{
	struct node *temp = (*head);
	while(temp)
	{
		(*tail) = temp;
		temp = temp->next;
	}
}

void print(struct node **head)
{
	bool zero = true;
	struct node *temp;
	temp = *head;
	if(temp == NULL)
	{
		printf("number length is zero\n");
		return;
	}
	while(temp != NULL)
	{
		if((temp->value == 0) && zero)
		{
			if(temp->next == NULL)
				printf("0");
			temp = temp->next;
		}
		else
		{
			printf("%d", temp->value);
			temp = temp->next;
			zero = false;
		}
	}
	printf("\n");
}

int checkLargest(struct node **h1, struct node **h2)
{
	struct node *temp1, *temp2;
	temp1 = (*h1);
	temp2 = (*h2);
	while(temp1 != NULL)
	{
		if(temp1->value > temp2->value)
			return 1;
		else if(temp2-> value > temp1->value)
			return 2;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return 0;
}

void reverse(struct node **head, struct node **tail)
{
	struct node *Next, *temp, *looper;
	Next = (*head)->next;
	looper = *head;
	(*head)->next = NULL;
	while(Next != NULL)
	{
		temp = Next;
		Next = (*temp).next;
		(*temp).next = looper;
		looper = temp;
	}
	temp = (*tail);
	(*head) = (*tail);
	(*tail) = temp;
}

void difference_of_digits(struct node **h1, struct node **h2)
{
	if(*h1 != NULL && *h2 != NULL)
	{
		if((*h1)->value < (*h2)->value)
		{
			((*h1)->next)->value = ((*h1)->next)->value - 1;
			(*h1)->value = (*h1)->value + 10;
		}
		(*h1)->value = (*h1)->value - (*h2)->value;
		difference_of_digits(&((*h1)->next), &((*h2)->next));
	}
}

int main()
{
	int c;
	do
	{
		c = getchar();
		if(c != '\n')
			insert(&h1, &t1, c - '0');
	}
	while(c != '\n');
	do
	{
		c = getchar();
		if(c != '\n')
			insert(&h2, &t2, c - '0');
	}
	while(c != '\n');
	reverse(&h1, &t1);
	reverse(&h2, &t2);
	difference_of_digits(&h1, &h2);
	getTail(&h1, &t1);
	reverse(&h1, &t1);
	print(&h1);
	return 0;
}
