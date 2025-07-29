#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"functii.h"

int main()
{
	PERSONAL *tab_pers=0;
	int n;
	printf("n = ");
	scanf("%d",&n);
	getchar();

	char fisier[100];
	printf("Introduceti numele fisierului din care doriti sa cititi: ");
	fgets(fisier,sizeof(fisier),stdin);
	if(fisier[strlen(fisier)-1]=='\n')
		fisier[strlen(fisier)-1]='\0';

	FILE *f=fopen(fisier,"r");
	if(f==0)
	{
		fprintf(stderr,"Fisierul nu a putut fi deschis\n");
		exit(EXIT_FAILURE);
	}

	tab_pers=alocare(n);
	citire(tab_pers,n,f);
	afisare(tab_pers,n);
	printf("\nAfisare personal cu varsta mai mica de 30 de ani\n");
	afisare30(tab_pers,n);
	printf("\nAfisare personal in ordine alfabetica dupa nume:\n");
	afisareAlfabetic(tab_pers,n);

	return 0;	
}
