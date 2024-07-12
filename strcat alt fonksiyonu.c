//strcat alt fonksiyonu by Kaan Civelek 232805001
#include <stdio.h>
#define MAXKARAKTER 1000

char *birlestir(char *pkelime1, char *pkelime2);

int main (){
    char birincikelime[MAXKARAKTER], ikincikelime[MAXKARAKTER];
    printf("Kelimeleri giriniz: ");
    gets(birincikelime);
    gets(ikincikelime);
    birlestir(birincikelime, ikincikelime);
    printf("Birlestirilmis kelime: %s\n", birincikelime);
    return 0;
}

char *birlestir(char *pkelime1, char *pkelime2) {
    while (*pkelime1 != '\0') {
        pkelime1++;
    }

    while (*pkelime2 != '\0') {
        *pkelime1 = *pkelime2;
        pkelime1++;
        pkelime2++;
    }

    *pkelime1 = '\0';
    return pkelime1;
}
