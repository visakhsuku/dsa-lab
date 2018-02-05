#include <stdio.h>
#include <stdbool.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,index;
		scanf("%d",&n);
		index =n;
		int a[n];
		bool isIndex = false;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==0&!isIndex)
			{
				isIndex=true;
				index=i;
			}
		}
		printf("%d\n",(n-index));
	}
}
