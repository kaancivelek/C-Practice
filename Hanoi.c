#include <stdio.h>
// Ba�lang��=A  Yol=B  Biti�=C
// Kaan Civelek-232805001 Yaz�l�m M�hendisli�i 1. S�n�f 2. ��retim

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
