#include<stdio.h>
#include<string.h>

void rev(char s[100000],int i,int len)
{
	s[i]+=s[len-1-i];
	s[len-1-i]=s[i]-s[len-1-i];
	s[i]-=s[len-1-i];
	i++;
	if(i<len-1-i)
		return rev(s,i,len);
	else
		return;	
}


int main(){
	char s[100000];
	scanf("%s",s);
	rev(s,0,strlen(s));
	printf("%s\n",s);
	return 0;
}
