#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

long queue[MAX],rear=-1,front=-1,length=0,LIMIT;

void enqueue(int);
void dequeue();
void print_queue();

int main()
{
	scanf("%ld",&LIMIT);
	char c;
	while(1)
	{
		c = getchar();
		if(c == 's')
			return 0;
		else if(c == 'e')
		{
			long n;
			scanf("%ld",&n);
			enqueue(n);
		}
		else if(c == 'd')
			dequeue();
		else if(c == 'p')
			print_queue();
	}
	return 0;
}

void print_queue()
{
	if(length == 0)
	{
		printf("-1\n");
	}
	else
	{
		long temp = front;
		int i=0;
		for(i=0;i<length;i++,temp++)
		{
			if(temp>=LIMIT)
				temp-=LIMIT;
			printf("%ld ",queue[temp]);
		}
		printf("\n");
	}
}

void dequeue()
{
	if(length == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%ld\n",queue[front]);
		front++;
		length--;
		if(front>=LIMIT)
			front-=LIMIT;
	}
}

void enqueue(int ele)
{
	if((length != LIMIT))
	{
		if(front == -1)
			front = 0;
		rear = (rear+1)%LIMIT;
		queue[rear]=ele;
		length++;
	}
	else if(length == LIMIT)
	{
		printf("-2\n");
	}
}