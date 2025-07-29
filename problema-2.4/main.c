#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char c;
	int litere,cifre,separatori,cuvinte,propozitii,aliniate;
	int caractTotal=0;
	int inCuv=0;
	litere=cifre=separatori=cuvinte=propozitii=aliniate=0;
	int ult=0;

	printf("\nIntroduceti textul pentru analiza:\n\n");
	while((c=getchar())!=EOF)
	{
		if((c>='a' && c<='z')||(c>='A' && c<='Z'))
		{
			litere++;
			if(!inCuv)
			{
				cuvinte++;
				inCuv=1;
			}
		}
		else
		if(c>='0' && c<='9')
		{
			cifre++;
			if(!inCuv)
			{
				cuvinte++;
				inCuv=1;
			}
		}
		else
		if(c=='(' || c==')' || c=='[' || c==']' || c=='{' || c=='}' || c=='+' || c=='*' || c=='/' || c=='%' || c=='!')
		{
			separatori++;
			inCuv=0;
		}
		else
		if(c=='.')
		{
			propozitii++;
			inCuv=0;
		}
		else 
		if(c=='\n')
		{
			if(ult=='.')
				aliniate++;
			inCuv=0;
		}
		else
		if(c==' '||c==','||c==';'||c==':'||c=='-')
		{
			if(c=='-' && inCuv)
			{
				separatori++;
			}
			else
			{
				inCuv=0;
			}
		}
		else
		{
			inCuv=0;
		}	

		ult=c;
		caractTotal++;
	}

	printf("\n\nNumarul de caractere:\n");
	printf("\nLitere: %d\n",litere);
	printf("Cifre: %d\n",cifre);
	printf("Cuvinte: %d\n",cuvinte);
	printf("Separatori: %d\n",separatori);
	printf("Propozitii: %d\n",propozitii);
	printf("Aliniate: %d\n",aliniate);

	printf("\nStatistici: ");
	printf("Total caractere: %d\n",caractTotal);
	printf("Litere: %.2lf%%\n",(float)litere*100/caractTotal);
	printf("Cifre: %.2lf%%\n",(float)cifre*100/caractTotal);

	return 0;
}
