#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"functii.h"

void ulToX(unsigned long a, char x[])
{
	char cifreHex[]="0123456789ABCDEF";
	x[0]='0';
	x[1]='x';
	int i=0;

	if(a==0)
	{
		x[2]='0';
		x[3]='\0';
		return;
	}

	int nrCifre=0;
	unsigned long aux=a;
	while(aux!=0)
	{
		aux/=16;
		nrCifre++;
	}

	i=2+nrCifre-1;
	while(a>0)
	{
		int rest=a%16;
		x[i]=cifreHex[rest];
		a/=16;
		--i;
	}
	x[nrCifre+2]='\0';
}
