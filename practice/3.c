#include <stdio.h>
#include <stdbool.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int a[n];
	    int i,largest;
	    bool noLargest = true;
	    for(i=0;i<n;i++)
	    {
	        scanf("%d",&a[i]);
	        if(i>0&&noLargest)
	            if(a[i]-a[i-1]<0)
	                {
	                    largest = a[i-1];
	                    noLargest = false;
	                }
	    }
	    printf("%d\n",largest);
	}
	return 0;
}
