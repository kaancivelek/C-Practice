//Kaan Civelek 232805001
#include <stdio.h>
#include <stdlib.h>
FILE *file;

void dosyayaz()
{
    char oAD[15];
    int ogr_sayisi =2,i=0;
    int No,Not;
    FILE *file;
    file = fopen("ogrenci.txt","w");
    if (file==NULL){
        printf("ogrenci.txt dosyasi acilamadi.\n");
        exit (1);}
    printf("OGRENCI BILGILERINI GIRINIZ\n------------------------\n");
        while(i++<ogr_sayisi)
        {
            printf("Ogrenci Adini Giriniz");
            scanf("%s",oAD);

            printf("Ogrenci Numarasini Giriniz");
            scanf("%d",&No);

            printf("Ogrenci Notunu Giriniz");
            scanf("%d",&Not);
            printf("\n");
            fprintf(file,"%d %s %d\n",No,oAD,Not);
        }
    printf("Ogrenci Bilgileri Kaydedildi.\n\n");
    fclose(file);
    ;}

    void dosyaoku(){

    char Ad[10];
    int No,Not;
    FILE *file;
    file =fopen("ogrenci.txt","r");
        if (file==NULL){
            printf("ogrenci.txt dosyasi acilamadi.\n");
            exit (1);}

int csr;
        printf("Ogrenci Bilgleri Dosyadan Okunuyor\nOGRENCI BILGILERI\n-------------------\n");
        while (csr!=EOF){
            csr=fscanf(file,"%d%s%d",&No,Ad,&Not);
       if(csr!=EOF){
           printf("NO=%d \nAD=%s \nNOT=%d\n\n",No,Ad,Not);


       }

        }
        fclose(file);


}


int main(){
dosyayaz();

dosyaoku();

    return 0;
}