#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char fisier[100];
	printf("Introduceti numele fisierului: ");
	fgets(fisier,sizeof(fisier),stdin);
	if(fisier[strlen(fisier)-1]=='\n')
		fisier[strlen(fisier)-1]='\0';
	FILE *f=fopen(fisier,"r");
	if(f==0)
	{
		fprintf(stderr,"Fisierul nu a putut fi creat\n");
		exit(EXIT_FAILURE);
	}
	
	char text[100];
	printf("\nSe citeste textul din fisier...\n\n");
	printf("Textul: ");
	char c;
	while((c=getc(f))!=EOF)
	{
		putchar(c);
	}
	rewind(f);
	fgets(text,sizeof(text),f);
	if(text[strlen(text)-1]=='\n')
		text[strlen(text)-1]='\0';
	int indice=0;
	int nrLit=0;
	for(int i=0;i<=strlen(text);++i)
	{
		if(i<strlen(text) && !(isspace(text[i])))
			nrLit++;
		else
		{
			if(nrLit>0){
				printf("cuvant %d: %d litere\n",indice,nrLit);
				indice++;
			}
			nrLit=0;
		}
	}

	fclose(f);

	return 0;
}
