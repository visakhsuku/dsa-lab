#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int value;
	struct node *next, *prev;
};
struct node *head = NULL, *tail = NULL;

//function declarations
void enqueue(int);
void dequeue();
void print_queue();

int main()
{
	char c;
	while(1)
	{
		c = getchar();
		if(c == 's' || c == 'S')
			return 0;
		else if(c == 'e')
		{
			int ele;
			scanf("%d", &ele);
			enqueue(ele);
		}
		else if(c == 'd')
		{
			dequeue();
		}
		else if(c == 'p')
		{
			print_queue();
		}
	}
	return 0;
}

void dequeue()
{
	if(head == NULL)
	{
		printf("-1\n");
	}
	else if(head == tail)
	{
		int ele = head->value;

		printf("%d\n", ele);
		struct node *temp = head;
		head = tail = NULL;
		free(temp);
	}
	else
	{
		int ele = head->value;
		struct node *temp = head;
		printf("%d\n", ele);
		head = temp->next;
		free(temp);
	}
}

void print_queue()
{
	if(head == NULL)
	{
		printf("-1\n");
	}
	else
	{
		struct node *temp = head;
		while(temp != NULL)
		{
			printf("%d ", temp->value);
			temp = temp->next;
		}
		printf("\n");
	}
}

void enqueue(int ele)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->value = ele;
	new->next = NULL;
	new->prev = NULL;
	if(head == NULL)
	{
		head = new;
		tail = new;
	}
	else
	{
		tail->next = new;
		new->prev = tail;
		tail = new;
	}
}
