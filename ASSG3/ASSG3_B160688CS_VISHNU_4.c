#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000000
long heapSize = -1;

struct node
{
	long value;
	long priority;
} queue[MAX];

long LEFT(long i)
{
	return 2 * i + 1;
}

long RIGHT(long i)
{
	return 2 * (i + 1);
}

long PARENT(long i)
{
	if(i % 2 == 0)
		return i / 2 - 1;
	else
		return (i - 1) / 2;
}

void swap(long *a, long *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

void minHeapify(long);
void buildMinHeap();
void getMin();
void popMin();
void changePriority(long,long);
void push(long,long);

int main()
{
	char c;
	while(1)
	{
		c = getchar();
		if(c == 'a')
		{
			long value, priority;
			scanf("%ld %ld", &value, &priority);
			push(value, priority);
		}
		else if(c == 'e')
		{
			popMin();
		}
		else if(c == 'd')
		{
			long value, priority;
			scanf("%ld %ld", &value, &priority);
			changePriority(value, priority);
		}
					   else if(c == 's')
						   return 0;
		else if(c == 'g')
		{
			getMin();
		}
	}
	return 0;
}

void minHeapify(long i)
{
	long l = 2 * i + 1;
	long r = 2 * i + 2;
	long smallest;

	if(l <= heapSize && queue[l].priority < queue[i].priority)
		smallest = l;
	else
		smallest = i;
	if(r <= heapSize && queue[r].priority < queue[smallest].priority)
		smallest = r;
	if(smallest != i)
	{
		struct node temp = queue[i];
		queue[i] = queue[smallest];
		queue[smallest] = temp;
		minHeapify(smallest);
	}
}

void push(long value, long priority)
{
	heapSize++;
	queue[heapSize].value = value;
	queue[heapSize].priority = priority;
	buildMinHeap();
}

void popMin()
{
	if(heapSize == -1)
		printf("EMPTY\n");
	else
	{
		printf("%ld (%ld)\n", queue[0].value, queue[0].priority);
		queue[0] = queue[heapSize];
		heapSize -= 1;
		minHeapify(0);
	}

}

void getMin()
{
	if(heapSize == -1)
		printf("EMPTY\n");
	else
	{
		printf("%ld (%ld)\n", queue[0].value, queue[0].priority);
	}

}

void changePriority(long value, long newPriority)
{
	long i = 0;
	while(i <= heapSize)
	{
		if(queue[i].value == value)
		{
			queue[i].priority = newPriority;
			break;
		}
		else
			i++;
	}

	buildMinHeap();
}

void buildMinHeap()
{
	long i;
	for(i = PARENT(heapSize); i >= 0; i--)
		minHeapify(i);
}

