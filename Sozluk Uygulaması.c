//Sozluk Uygulaması By Kaan Civelek 232805001


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define KELIME_MAX_KARAKTER 50
#define TANIM_MAX_KARAKTER 500


typedef struct {
    char kelime[KELIME_MAX_KARAKTER];
    char tanim[TANIM_MAX_KARAKTER];
} Sozlukislem;


void sozlugeekle() {
    FILE *file = fopen("D:Sozluk.txt", "a");
    if (file == NULL) {printf("Dosya acilamadi"); exit(1);}

    Sozlukislem giris;
    printf("Kelime: ");
    scanf("%s", giris.kelime);

    getchar();

    printf("Tanım: ");
    fgets(giris.tanim, TANIM_MAX_KARAKTER, stdin);

    fprintf(file, "%s:%s", giris.kelime, giris.tanim);
    fclose(file);

    printf("Kelime başarıyla eklendi.\n");
}


void sozlukgoruntule() {
    FILE *file = fopen("D:Sozluk.txt", "r");
    if (file == NULL) {printf("Dosya acilamadi"); exit(1);}

    char buffer[KELIME_MAX_KARAKTER + TANIM_MAX_KARAKTER];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}


void tanimara() { // Bu fonksiyonu yazarken CHATGPT'den yardım aldım :(
    FILE *file = fopen("D:Sozluk.txt", "r");
    if (file == NULL) {printf("Dosya acilamadi"); exit(1);}

    char kelime[KELIME_MAX_KARAKTER];
    printf("Aranacak kelime: ");
    scanf("%s", kelime);

    char buffer[KELIME_MAX_KARAKTER + TANIM_MAX_KARAKTER];
    int found = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, ":");
        if (strcmp(token, kelime) == 0) {
            printf("Tanım: %s", strtok(NULL, "\n"));
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Kelime bulunamadı.\n");
    }

    fclose(file);
}


int main() {
    int csr;

    do {
        printf("\nSozluk Uygulamasi.\n");
        printf("1. Yeni kelime ve tanim ekle.\n");
        printf("2. Sozlugu goruntule.\n");
        printf("3. Belirli bir kelimenin tanimini ara.\n");
        printf("4. Cik.\n");
        scanf("%d", &csr);


        switch (csr) {
            case 1:
                sozlugeekle();
                break;
            case 2:
                sozlukgoruntule();
                break;
            case 3:
                tanimara();
                break;
            case 4:
                printf("Programdan cikili4yor...\n");
                break;
            default:
                printf("Gecersiz secim.\n");
                break;
        }

    } while (csr != 4);

    return 0;
}
