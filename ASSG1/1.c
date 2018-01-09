#include<stdio.h>

int main(){
	int choice,len,k;
	scanf("%d",&choice);
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
		if(s[i]>='a' && s[i]<='z')
                {
        		s[i]-='a';
			s[i]+=k;
			s[i]+=26;
			s[i]%=26;
			s[i]+='a';
		}
		if(s[i]>='A' && s[i]<='Z')
		{
			s[i]-='A';
			s[i]+=k;
			s[i]+=26;
			s[i]%=26;
			s[i]+='A';
		}
	}
	printf("%s\n",s);
	return 0;
}

