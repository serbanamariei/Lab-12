#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
	FILE *f=fopen("p11.c","r");
	if(f==0)
	{
		fprintf(stderr,"Nu s-a putut deschide fisierul\n");
		exit(EXIT_FAILURE);
	}

	char c,urm;
	int linie=0;
	int bloc=0;

	while((c=fgetc(f))!=EOF)
	{
		if(linie)
		{
			if(c=='\n')
			{
				linie=0;
				putchar(c);
			}
			continue;
		}

		if(bloc)
		{
			urm=fgetc(f);
			if(urm=='/')
			{
				bloc=0;
			}
			else
			if(urm!=EOF)
			{
				ungetc(urm,f);
			}
			continue;
		}

		if(c=='/')
		{
			urm=fgetc(f);
			if(urm=='/')
			{
				linie=1;
				continue;
			}
			else
			if(urm=='*')
			{
				bloc=1;
				continue;
			}
			else
			{
				putchar(c);
				if(urm!=EOF) ungetc(urm,f);
			}
		}
		else
		{
			putchar(c);
		}
	}
	fclose(f);

	return 0;
}
