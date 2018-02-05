#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],t,i,j,k;
	i=0;j=n-1;
	for(k=0;k<n;k++)
	{
		scanf("%d",&t);
		if(t%2==0)
		{
			a[i]=t;
			i++;
		}
		else
		{
			a[j]=t;
			j--;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
