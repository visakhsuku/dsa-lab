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

void reverse() {
	struct node *Next,*temp,*looper;
	Next = (*head).next;
	looper = head;
	(*head).next=NULL;
	while(Next!=NULL) {
		temp = Next;
		Next = (*temp).next;
		(*temp).next=looper;
		looper = temp;
	}
	temp = tail;
	head = tail;
	tail = temp;
}

int main() {
	int n,i,a;
	printf("Enter number of terms : ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a);
		insert(a);
	}
	printf("Original input : \n");
	print();
	reverse();
	printf("Reversed input : \n");
	print();
	return 0;
}
