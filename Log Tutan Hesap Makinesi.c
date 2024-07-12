#include <stdio.h>
#include <stdlib.h>

// Log tutan hesap makinesi by Kaan Civelek
FILE *file;
int hesapmakinesi( int a, int b) {

    file= fopen("d:a.txt","a+");
    if (file==NULL){ printf("\nDosya olusturulamadi."); exit (1);}
    int count=1;
char buffer;
do {

    int nav;
    printf("Hangi islemi yapmak istiyorsunuz ? \n1)Toplama\n2)Cikarma\n3)Carpma\n4)Bolme\n");
    scanf("%d", &nav);


    int cache;
    switch (nav) {


        case 1:
            cache=a+b;
            printf("\n %d+%d=%d\n",a,b,cache);
            fprintf(file,"%d. %d+%d=%d\n",count,a,b,cache);

            break;

        case 2:
            cache=a-b;
            printf("\n %d-%d=%d\n",a,b,cache);
            fprintf(file,"%d. %d-%d=%d\n",count,a,b,cache);
            break;

        case 3:
            cache=a*b;
            printf("\n %d*%d=%d\n",a,b,cache);
            fprintf(file,"%d. %d*%d=%d\n",count,a,b,cache);
            break;

        case 4:
            cache=a/b;
            printf("\n %d/%d=%d\n",a,b,cache);
            fprintf(file,"%d. %d/%d=%d\n",count,a,b,cache);
            break;


        default:

            printf("Uygun olmayan giris.");
            break;
    }

    printf("\nTekrar islem yapmak istemiyorsaniz 'n'/'N' yaziniz.\n");
scanf(" %c", &buffer);
    if (buffer=='n'||buffer=='N'){break;}
count++;
}while(1);
fclose(file);

}
    int main() {

        printf("Iki sayiyi Sirayla giriniz.");
int cache0, cache1;
        scanf("%d %d",&cache0, &cache1);

        hesapmakinesi(cache0,cache1);

        return 0;
    }


