#include<stdio.h>

int main(){
	int choice,len,k;
	printf("Enter choice : ");
	scanf("%d",&choice);
	printf("Enter length : ");
	scanf("%d",&len);
	char s[len];
	scanf(" %[^\n]s",s);
	scanf("%d",&k);
	k%=26;
	int i=0;
	if(choice == 2)
	{
		k=-1*k;
	}
	for(i=0;i<len;i++)
	{
		if(s[i]>='A' && s[i]<='Z')
                {
        		s[i]-='A';
			s[i]+=k;
			s[i]+=26;
			s[i]%=26;
			s[i]+='A';
		}
		if(s[i]>='a' && s[i]<='z')
		{
			s[i]-='a';
			s[i]+=k;
			s[i]+=26;
			s[i]%=26;
			s[i]+='a';
		}
	}
	printf("%s\n",s);
	return 0;
}

