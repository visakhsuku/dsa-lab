#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],k,i,j;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	i=0;j=n-1;
	while(i<j)
	{
		if(a[i]+a[j] == k)
		{
			printf("%d %d",a[i],a[j]);
			return 0;
		}
		else if(a[i]+a[j] > k)
			j--;
		else
			i++;
	}
	printf("no desired output");
	return 0;
}
