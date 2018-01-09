#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void transpose(int n, int a[n][n], int i, int j)
{
	if((i == n - 1) && (j == n - 1))
		return;
	if(j < i)
	{
		a[i][j] += a[j][i];
		a[j][i] = a[i][j] - a[j][i];
		a[i][j] -= a[j][i];
		return transpose(n, a, i, j + 1);
	}
	else
		return transpose(n, a, i + 1, 0);
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n][n];
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
		{
			if(j != n - 1)
				scanf("%d ", &a[i][j]);
			else
				scanf("%d", &a[i][j]);
		}
	transpose(n, a, 1, 0);
	int t = 1, il = 1, iu = n, jl = 0, ju = n, count = 0;;
	i = 0;
	j = 0;
	while(1)
	{
		if(t == 1)
		{
			if(j == ju - 1)
			{
				t = 2;
				ju--;
			}
		}
		if(t == 2)
		{
			if(i == iu - 1)
			{
				t = 3;
				iu--;
			}
		}
		if(t == 3)
		{
			if(j == jl)
			{
				t = 4;
				jl++;
			}
		}
		if(t == 4)
		{
			if(i == il)
			{
				t = 1;
				il++;
			}
		}
		printf("%d ", a[i][j]);
		count++;
		if(count == n * n)
			break;
		if(t == 1)
			j++;
		else if(t == 2)
			i++;
		else if(t == 3)
			j--;
		else if(t == 4)
			i--;
	}
	return 0;
}

