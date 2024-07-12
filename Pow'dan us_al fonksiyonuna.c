#include <stdio.h>

//POW==>us_al
//Kaan Civelek 232805001 Yazılım Nühendisliği 1.Sınıf 2.Öğretim




int us_al(int taban, int us);



int main(){
int x,n;
int cache0,cache1;
printf("Taban degerini giriniz: ");
scanf("%d",&x);
printf("\nUs degerini giriniz: ");
scanf("%d",&n);
cache0=x;
cache1=n;
printf("%d^%d=%d",cache0,cache1,us_al(x,n));

return 0;
}












int us_al(int taban, int us){
int cache;
cache =taban;
for(;us>1;us--){

    taban*=cache;

}
return taban;

}

