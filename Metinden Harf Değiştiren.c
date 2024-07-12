// Girilen metnin istenilen harfini degistiren ve degistirilmis metni dosyalayan C algoritması by Kaan Civelek 232805001 

#include <stdio.h>
#include <stdlib.h>
#define MAX_CHARACTER 100000

FILE *fl;
int metinsakla(FILE *file, char *metin);
int harfdegistir(char *input_path, char *output_path, char c1, char c2);

int main() {
    fl = fopen("d:\\metin.txt", "w+");
    if (fl == NULL) {
        printf("Dosya açılamadı.\n");
        return 1;
    }

    printf("Metini giriniz. (Max 100bin karakter)\n");
    char txt[MAX_CHARACTER];
    fgets(txt, MAX_CHARACTER, stdin);
    metinsakla(fl, txt);

    printf("\nHangi harfi hangi harfle degistirmek istiyorsunuz ? Sirayla giriniz ");
    char c1, c2;
    scanf(" %c %c", &c1, &c2);
printf("\n%c=>>>%c",c1,c2);
    fclose(fl); //

    harfdegistir("d:\\metin.txt", "d:\\yenimetin.txt", c1, c2);

    return 0;
}

int metinsakla(FILE *file, char *metin) {
    return fprintf(file, "%s", metin);
}

int harfdegistir( char *input_path, char *output_path, char c1, char c2) {
    FILE *file = fopen(input_path, "r");
    if (file==NULL) {
        printf("Girdi dosyası açılamadı.\n");
        return 1;
    }

    char cache[MAX_CHARACTER];
    //fread(cache, 1, MAX_CHARACTER, file);
    fscanf(file,"%[^\n]",cache);
    fclose(file);


    for (int i = 0; cache[i] != '\0'; i++) {
        if (cache[i] == c1) {
            cache[i] = c2;
        }
    }

    FILE *newfile = fopen(output_path, "w");
    if (!newfile) {
        printf("Çıktı dosyası açılamadı.\n");
        return 1;
    }

    fprintf(newfile, "%s", cache);
    fclose(newfile);

    return 0;
}
