#include <stdio.h>
// Baþlangýç=A  Yol=B  Bitiþ=C
// Kaan Civelek-232805001 Yazýlým Mühendisliði 1. Sýnýf 2. Öðretim

void HanoiKuleleri(int diskmiktari, char A, char C, char B)
{
    if (diskmiktari == 1)
    {
        printf("\n %d numarali disk %c >>> %c seklinde ilerliyor.",diskmiktari, A, C);
        return;
    }
    HanoiKuleleri(diskmiktari-1, A, B, C);
    printf("\n %d numarali disk %c >>> %c seklinde ilerliyor.", diskmiktari, A, C);
    HanoiKuleleri(diskmiktari-1, B, C, A);
}





int main()
{
    int adimmiktari,x =0;
    printf("Disk miktarini giriniz.");
    scanf("%d",&x);
    HanoiKuleleri(x, 'A', 'C', 'B');
adimmiktari=pow(2,x);

printf("\n%d adimda islem tamamlandi.",--adimmiktari);
return 0;
}
