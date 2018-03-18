#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

struct node
{
	long value;
	struct node *next;
}*head, *tail;

long convertToInt(char str[MAX])
{
	long i, a = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		a *= 10;
		a += (str[i] - 48);
	}
	return a;
}

void insert(long val)
{
	struct node *new = malloc(sizeof(struct node));
	(*new).value = val;
	(*new).next = NULL;
	if(head == NULL)
	{
		head = new;
		tail = new;
	}
	else
	{
		(*tail).next = new;
		tail = new;
	}
}

void print()
{
	struct node *temp = head;
	while(temp != NULL)
	{
		printf("%ld ", (*temp).value);
		temp = (*temp).next;
	}
	printf("\n");
}

void reverse()
{
	struct node *Next, *temp, *looper;
	Next = (*head).next;
	looper = head;
	(*head).next = NULL;
	while(Next != NULL)
	{
		temp = Next;
		Next = (*temp).next;
		(*temp).next = looper;
		looper = temp;
	}
	temp = tail;
	head = tail;
	tail = temp;
}

int main()
{
	char str[MAX],substr[MAX];
	scanf("%[^\n]s", str);
	long i,k=0;
	i = 0;
	while(1)
	{
		if(str[i] == ' ' || str[i] == '\0')
		{
			substr[k] = '\0';
			
				long ele = convertToInt(substr);
//				printf("%d\n", ele);
				insert(ele);
			k = 0;
			if(str[i] == '\0')
				break;
		}
		else
		{
			substr[k] = str[i];
			k++;
		}
		i++;
	}
	reverse();
	print();
	return 0;
}
