#include <stdio.h>
#include <stdlib.h> // For exit()
 
int main()
{
    FILE *fptr1, *fptr2;
    char c,t='a';
    fptr1 = fopen("in.txt", "r");
    fptr2 = fopen("out.txt", "w");
 
    c = fgetc(fptr1);
    while (c != EOF)
    {
    	if(c!=' '&&c!='\t')
        	fputc(c, fptr2);
        else
		{
			if(t!=' ')
				fputc(' ', fptr2);
		}
        t=c;
        if(c=='\t')
        	t=' ';
		c = fgetc(fptr1);
    }
 
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}