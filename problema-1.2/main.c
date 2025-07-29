#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char text[100];
	printf("Introduceti textul dvs: ");
	char c;
	int i=0;
	while((c=getchar())!=EOF && i<99)
	{
		text[i]=c;
		i++;
	}
	text[i]='\0';

	int nr=0;
	char vocale[10]={'a','e','i','o','u','A','E','I','O','U'};
	for(int i=0;i<strlen(text);++i)
		if(strchr(vocale,text[i]))
		   nr++;
	printf("In textul dvs au existat %d vocale\n",nr);

	return 0;
}
