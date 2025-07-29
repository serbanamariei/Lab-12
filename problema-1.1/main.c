#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char text[100];
	int nr=0;
	printf("Introduceti textul: ");
	char c;
	int i=0;
	while((c=getchar())!=EOF && i<99)
	{
		text[i]=c;
		i++;
	}
	text[i]='\0';
	
	clearerr(stdin);
	printf("Introduceti caracterul a carui aparitii doriti sa le numarati: ");
	char caract;
	scanf(" %c",&caract);
	
	for(int i=0;i<strlen(text);++i)
		if(text[i]==caract)
			nr++;
	printf("Caracterul \'%c\' a aparut in textul dvs de %d ori\n",caract,nr);

	return 0;
}
