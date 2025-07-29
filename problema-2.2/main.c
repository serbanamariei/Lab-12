#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"functii.h"

int main()
{
	unsigned long a;
	printf("a = ");
	scanf("%lu",&a);

	char x[50];
	ulToX(a,x);

	printf("Numarul convertit la baza 16: ");
	for(int i=0;i<strlen(x);++i)
		printf("%c",x[i]);

	printf("\n");

	return 0;
}
