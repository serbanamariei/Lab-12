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
		fprintf(stderr,"Fisierul nu a putut fi deschis\n");
		exit(EXIT_FAILURE);
	}

	int alegere;
	printf("Alegeti tipul de prelucrare:\n1) Litere mari -> litere mici\n2) Litere mici -> litere mari\nalegere -->  ");
	scanf("%d",&alegere);
	printf("\nSe citeste continutul fisierului ...\n");
	char linie[30];
	while(fgets(linie,sizeof(linie),f))
	{
		printf("\nLinia: ");
		puts(linie);
		printf("trece in: ");
		if(alegere==1)
			for(int i=0;i<strlen(linie);++i)
				printf("%c",tolower(linie[i]));
		else if(alegere==2)
			for(int i=0;i<strlen(linie);++i)
				printf("%c",toupper(linie[i]));
	}

	return 0;
}
