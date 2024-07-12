#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Girilen Kelimeleri karıştırıp Kelime düzeltmece oyunu için sorular hazırlayan ve cevapları saklayan kod. by Kaan Civelek 232805001

FILE *file, *file0;

void karistir(char *dizi, size_t n) {
    if (n > 1) {
        for (size_t i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            char t = dizi[j];
            dizi[j] = dizi[i];
            dizi[i] = t;
        }
    }
}

int main() {
file =fopen("D:cevaplar.txt","a+"); if (file==NULL){ printf("Konum / Dosya sorunu."); exit(1);}
    file0 =fopen("D:sorular.txt","a+"); if (file0==NULL){ printf("Konum / Dosya sorunu."); exit(1);}

srand(time(NULL));
fputs("\n*--------------*\n",file);
fputs("\n*--------------*\n",file0);
while(1) {

    char word[50], cache[50];
    printf("Kelimenizi giriniz. MAX. 50 Karakter");
    gets(word);
    strcpy(cache, word);


    size_t length = strlen(cache);

    karistir(word, length);


    fputs(word, file0);
fputc('\n',file0);
fputs(cache, file);
    fputc('\n',file);

    char csr;
    printf("Devam etmek istiyor musunz ? Bitirmek için n || N");
    csr= getchar();
    if(csr=='N'||csr=='n'){break;}
}
fclose(file);
fclose(file0);
    return 0;
}
