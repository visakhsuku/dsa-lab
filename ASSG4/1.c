#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void linearProbing();
void quadraticProbing();
void doubleHashing();
void chaining();

int main()
{
	char _ch;
	scanf("%c",&_ch);
	if(_ch=='a')
		linearProbing();
	else if(_ch=='b')
		quadraticProbing();
	else if(_ch=='c')
		doubleHashing();
	else if(_ch=='d')
		chaining();
	return 0;
}

void linearProbing()
{
	
}