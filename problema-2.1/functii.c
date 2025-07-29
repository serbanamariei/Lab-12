#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"functii.h"


PERSONAL *alocare(int n)
{
	PERSONAL *tab_pers=0;
	tab_pers=(PERSONAL *)malloc(n*sizeof(PERSONAL));
	if(tab_pers==0)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}

	for(int i=0;i<n;++i)
	{
		tab_pers[i].nume=(char *)malloc(20*sizeof(char));
		if(tab_pers[i].nume==0)
		{
			fprintf(stderr,"Memorie insuficienta\n");
			exit(EXIT_FAILURE);
		}

		tab_pers[i].prenume=(char *)malloc(20*sizeof(char));
		if(tab_pers[i].prenume==0)
		{
			fprintf(stderr,"Memorie insuficienta\n");
			exit(EXIT_FAILURE);
		}
	}

	return tab_pers;
}

void citire(PERSONAL *tab_pers, int n, FILE *f)
{
	printf("Se citesc datele personalului din fisier ...\n");
	for(int i=0;i<n;++i)
	{
		fgets(tab_pers[i].nume,20,f);
		if(tab_pers[i].nume[strlen(tab_pers[i].nume)-1]=='\n')
			tab_pers[i].nume[strlen(tab_pers[i].nume)-1]='\0';
		
		fgets(tab_pers[i].prenume,20,f);
		if(tab_pers[i].prenume[strlen(tab_pers[i].prenume)-1]=='\n')
			tab_pers[i].prenume[strlen(tab_pers[i].prenume)-1]='\0';

		fscanf(f," %d",&tab_pers[i].varsta);
		getc(f);
	}
}

void afisare(PERSONAL *tab_pers, int n)
{
	printf("Personalul dvs:\n\n");
	for(int i=0;i<n;++i)
	{
		printf("Nume: ");
		puts(tab_pers[i].nume);
		printf("Prenume: ");
		puts(tab_pers[i].prenume);
		printf("Varsta: %d\n\n",tab_pers[i].varsta);
	}
}

void afisare30(PERSONAL *tab_pers, int n)
{
	for(int i=0;i<n;++i)
		if(tab_pers[i].varsta<30)
		{
			printf("\nNume: ");
			puts(tab_pers[i].nume);
			printf("\nPrenume: ");
			puts(tab_pers[i].prenume);
			printf("\nVarsta: %d\n",tab_pers[i].varsta);
		}
}

void afisareAlfabetic(PERSONAL *tab_pers, int n)
{
	for(int i=0;i<n-1;++i)
		for(int j=i+1;j<n;++j)
			if(strcmp(tab_pers[i].nume,tab_pers[j].nume)>0)
			{
				char *aux;
				aux=tab_pers[i].nume;
				tab_pers[i].nume=tab_pers[j].nume;
				tab_pers[j].nume=aux;

				aux=tab_pers[i].prenume;
				tab_pers[i].prenume=tab_pers[j].prenume;
				tab_pers[j].prenume=aux;

				int a=tab_pers[i].varsta;
				tab_pers[i].varsta=tab_pers[j].varsta;
				tab_pers[j].varsta=a;
			}
	afisare(tab_pers,n);
}
