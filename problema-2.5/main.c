#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char c, prop[1000];
    int index = 0;
	
    printf("Introduceti cuvinte (terminate cu punct):\n");
    
    // Citire corectă a textului până la punct
    while((c = getchar()) != '.' && index < 999)
    {
        prop[index] = c;
        index++;
    }
    prop[index] = '\0'; // Terminare string
    
    char vocale[11] = "aeiouAEIOU";
    int i = 0;
    int lungime=strlen(prop);
    printf("\nCuvintele despartite in silabe:\n\n");
    
    // Procesează fiecare cuvânt
    int start_cuvant = 0;
    
    while(i < lungime && (prop[i]==' ' || prop[i]=='\n' || prop[i]=='\t'))
    {
		i++;
	}
	start_cuvant=i;

	while(i<=lungime)
	{
        // Când găsim spațiu, newline sau sfârșitul string-ului, procesăm cuvântul
        if(i==lungime || prop[i] == ' ' || prop[i] == '\n' || prop[i] == '\t')
        {
            if(i > start_cuvant) // Avem un cuvânt de procesat
            {
                // Afișăm cuvântul original
                printf("Cuvant: ");
                for(int k = start_cuvant; k < i; k++)
                {
                    printf("%c", prop[k]);
                }
                printf("\nSilabe: ");
                
                // Despărțim în silabe
                for(int j = start_cuvant; j < i; j++)
                {
                    printf("%c", prop[j]);
                    
                    // Verificăm dacă trebuie să punem cratimă
                    if(j < i - 1) // Nu suntem la ultimul caracter din cuvânt
                    {
                        // Regula 1: o consoană între două vocale trece în silaba a doua
                        if(strchr(vocale, prop[j]) && !strchr(vocale, prop[j+1]) && j < i - 2 && strchr(vocale, prop[j+2]))
                        {
                            printf("-");
                        }
                        // Regula 2: două sau mai multe consoane între vocale
                        else if(strchr(vocale, prop[j]) && !strchr(vocale, prop[j+1]) && j < i - 2 && !strchr(vocale, prop[j+2]))
                        {
                            // Prima consoană rămâne în prima silabă
                            printf("%c-", prop[j+1]);
                            j++; // Sărim peste prima consoană (deja afișată)
                        }
                    }
                }
                printf("\n\n");
            }
            
			i++;
            // Sărim peste spațiile consecutive
            while(i < lungime && (prop[i] == ' ' || prop[i] == '\n' || prop[i] == '\t'))
            {
                i++;
            }
            start_cuvant = i;
        }
		else
		{
			i++;
		}
    }
    
    return 0;
}
