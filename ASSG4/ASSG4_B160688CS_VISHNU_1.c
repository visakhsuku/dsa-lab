#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	long int key;
	struct node *next;
}*Hash, *temp, *prev;


void linearProbing();
void quadraticProbing();
void doubleHashing();
void chaining();

bool checkPrime(int x)
{
	int i;
	for(i = 2; i < x; i++)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}

int findPrime(int x)
{
	x--;
	while(x > 2)
	{
		if(checkPrime(x))
			return x;
		x--;
	}
	return x;
}

int main()
{
	char _ch;
	scanf("%c", &_ch);
	if(_ch == 'a')
		linearProbing();
	else if(_ch == 'b')
		quadraticProbing();
	else if(_ch == 'c')
		doubleHashing();
	else if(_ch == 'd')
		chaining();

	return 0;
}

void linearProbing()
{
	int m, i, ele;
	scanf("%d", &m);
	int hashTable[m];
	for(i = 0; i < m; i++)
	{
		hashTable[i] = 0;
	}
	char c;
	while(1)
	{
		scanf("%c", &c);
		if(c == 'i')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + i) % m;
				if(hashTable[hashValue] == 0)
				{
					hashTable[hashValue] = ele;
					break;
				}
			}
		}
		else if(c == 's')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + i) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						printf("1\n");
						break;
					}
				}
				else
				{
					printf("-1\n");
					break;
				}
			}
		}
		else if(c == 'd')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + i) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						hashTable[hashValue] = -1;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		else if(c == 'p')
		{
			for(i = 0; i < m; i++)
			{
				if(hashTable[i] > 0)
					printf("%d (%d)\n", i, hashTable[i]);
				else
					printf("%d ()\n", i);
			}
		}
		else if(c == 't')
		{
			return;
		}
	}
}

void quadraticProbing()
{
	int m, i, ele;
	scanf("%d", &m);
	int hashTable[m];
	for(i = 0; i < m; i++)
	{
		hashTable[i] = 0;
	}
	char c;
	while(1)
	{
		scanf("%c", &c);
		if(c == 'i')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * i) % m) % m;
				if(hashTable[hashValue] == 0)
				{
					hashTable[hashValue] = ele;
					break;
				}
			}
		}
		else if(c == 's')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * i) % m) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						printf("1\n");
						break;
					}
				}
				else
				{
					printf("-1\n");
					break;
				}
			}
		}
		else if(c == 'd')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * i) % m) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						hashTable[hashValue] = -1;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		else if(c == 'p')
		{
			for(i = 0; i < m; i++)
			{
				if(hashTable[i] > 0)
					printf("%d (%d)\n", i, hashTable[i]);
				else
					printf("%d ()\n", i);
			}
		}
		else if(c == 't')
		{
			return;
		}
	}
}

void doubleHashing()
{
	int m, i, ele;
	scanf("%d", &m);
	int hashTable[m];
	int r = findPrime(m);
	for(i = 0; i < m; i++)
	{
		hashTable[i] = 0;
	}
	char c;
	while(1)
	{
		scanf("%c", &c);
		if(c == 'i')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * (r - ele % r)) % m) % m;
				if(hashTable[hashValue] == 0)
				{
					hashTable[hashValue] = ele;
					break;
				}
			}
		}
		else if(c == 's')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * (r - ele % r)) % m) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						printf("1\n");
						break;
					}
				}
				else
				{
					printf("-1\n");
					break;
				}
			}
		}
		else if(c == 'd')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * (r - ele % r)) % m) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						hashTable[hashValue] = -1;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		else if(c == 'p')
		{
			for(i = 0; i < m; i++)
			{
				if(hashTable[i] > 0)
					printf("%d (%d)\n", i, hashTable[i]);
				else
					printf("%d ()\n", i);
			}
		}
		else if(c == 't')
		{
			return;
		}
	}
}

void chaining()
{
	int m, i, ele, ind;
	scanf("%d", &m);
	Hash = (struct node*)malloc(m * sizeof(struct node));
	for(i = 0; i < m; i++)
		Hash[i].next = NULL;
	char c;
	while(1)
	{
		scanf("%c", &c);
		if(c == 'i')
		{
			scanf("%d", &ele);
			ind = ele % m;
			struct node *new_node = (struct node*) malloc(sizeof(struct node));
			new_node->key = ele;
			new_node->next = NULL;
			if(Hash[ind].next == NULL)
				Hash[ind].next = new_node;
			else
			{
				temp = Hash[ind].next;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = new_node;
			}
		}
		else if(c == 's')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				if((Hash[i].next) != NULL)
				{
					temp = Hash[i].next;
					while(temp != NULL)
					{
						if((temp->key) == ele)
						{
							printf("1\n");
							return;
						}
						temp = temp->next;
					}
				}
			}
			if(i == m)
				printf("-1\n");
		}
		else if(c == 'd')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				if((Hash[i].next) != NULL)
				{
					prev = &Hash[i];
					temp = Hash[i].next;
					while(temp != NULL)
					{
						if((temp->key) == ele)
						{
							prev->next = temp->next;
						}
						prev = temp;
						temp = temp->next;
					}
				}
			}
		}
		else if(c == 'p')
		{
			for(i = 0; i < m; i++)
			{
				printf("%d(", i);
				if((Hash[i].next) != NULL)
				{
					temp = Hash[i].next;
					while((temp->next) != NULL)
					{
						printf("%ld ", temp->key);
						temp = temp->next;
					}
					printf("%ld)", temp->key);
				}
				else
				{
					printf(")");
				}
				printf("\n");
			}
		}
		else if(c == 't')
		{
			return;
		}
	}
}
