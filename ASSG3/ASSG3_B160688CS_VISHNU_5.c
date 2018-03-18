#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

#define MAX 10000

struct stack
{
	int value;
	struct stack *next;
} *head;

int convertToInt(char str[MAX])
{
	int i, a = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		a *= 10;
		a += (str[i] - 48);
	}
	return a;
}

int pop(struct stack **head)
{
	int ele = (*head)->value;
	struct stack *temp = (*head) ;
	(*head) = (*head)->next;
	free(temp);
	return ele;
}

void push(struct stack **head, int ele)
{
	struct stack *new = (struct stack*) malloc(sizeof(struct stack));
	new->value = ele;
	new->next = NULL;
	if(head == NULL)
		(*head) = new;
	else
	{
		new->next = (*head);;
		(*head) = new;
	}
}

int main()
{
	char str[MAX], substr[MAX], infix[MAX];
	scanf("%[^\n]s", str);
	int i = 0, k = 0, a=0, inLen = -1, j;
	for(i = 0; i < MAX; i++)
		infix[i] = -1;
	i = 0;
	while(1)
	{
		if(str[i] == ' ' || str[i] == '\0')
		{
			substr[k] = '\0';
//			printf("%s\n", substr);
			if(substr[0] == '*')
			{
//				printf("inside %s\n", substr);
				int a = pop(&head);
				int b = pop(&head);
				push(&head, b * a);
			}
			else if(substr[0] == '/')
			{
//				printf("inside %s\n", substr);
				int a = pop(&head);
				int b = pop(&head);
				push(&head, b / a);
			}
			else if(substr[0] == '+')
			{
//				printf("inside %s\n", substr);
				int a = pop(&head);
				int b = pop(&head);
				push(&head, b + a);
			}
			else if(substr[0] == '-')
			{
//				printf("inside %s\n", substr);
				int a = pop(&head);
				int b = pop(&head);
				push(&head, b - a);
			}
			else if(substr[0] == '%')
			{
//				printf("inside %s\n", substr);
				int a = pop(&head);
				int b = pop(&head);
				push(&head, b % a);
			}
			else
			{
				int ele = convertToInt(substr);
//				printf("%d\n", ele);
				push(&head, ele);
			}
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
	i = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ' ')
		{
			if((i > 0) && (str[i - 1] >= '0') && (str[i - 1] <= '9'))
			{
				infix[++inLen] = a;
				a = 0;
				inLen++;
			}
		}
		else if((str[i] >= '0') && (str[i] <= '9'))
		{
			a = a * 10 + (int)str[i] - 48;
		}
		else
		{
			j = inLen - 2;
			while(infix[j] != -1)
				j -= 2;
			infix[j] = (int)str[i];
		}
	}
	
	for(i = 0; i <= inLen; i++)
	{
		if(i % 2 == 0)
			printf("%d", infix[i]);
		else
			printf("%c", infix[i]);
	}
	printf("\n%d\n", pop(&head));
	return 0;
}
