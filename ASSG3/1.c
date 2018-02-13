#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
}*head,*tail;

void insert(int val) {
	struct node *new = malloc(sizeof(struct node));
	(*new).value=val;
	(*new).next=NULL;
	if(head == NULL) {
		head=new;
		tail=new;
	}
	else {
		(*tail).next=new;
		tail=new;
	}
}

void print()
{
	struct node *temp = head;
	while(temp!=NULL) {
		printf("%d ",(*temp).value);
		temp = (*temp).next;
	}
	printf("\n");
}

int main() {
	insert(1);
	insert(2);
	insert(4);
	print();
	return 0;
}
