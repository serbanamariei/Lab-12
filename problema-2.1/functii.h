#ifndef FUNCTII_H_
#define FUNCTII_H_

struct _PERSONAL{
	char *nume;
	char *prenume;
	int varsta;
};
typedef struct _PERSONAL PERSONAL;

PERSONAL *alocare(int n);
void citire(PERSONAL *tab_pers, int n, FILE *f);
void afisare(PERSONAL *tab_pers, int n);
void afisare30(PERSONAL *tab_pers, int n);
void afisareAlfabetic(PERSONAL *tab_pers, int n);

#endif
