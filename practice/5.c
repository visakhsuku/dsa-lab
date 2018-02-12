#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
		{
			   scanf("%d",&a[i]);
			   if(i>0)
			   {
			   		a[i-1]=a[i-1]^a[i];
			   }	
		}
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}