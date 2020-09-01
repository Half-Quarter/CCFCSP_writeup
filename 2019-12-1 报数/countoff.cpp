
#include <iostream>

using namespace std;

int countoff() {
    int total;
    int a=0,b=0,c=0,d=0;
    scanf("%d",&total);
    for(int i=1;i<=total;i++){
        if(i%7==0||(i%100)/10==7||i%10==7||i/100==7){
            total++;
            if(i%4==0){
                d++;
            }
            else if(i%4==1){
                a++;
            }
            else if(i%4==2){
                b++;
            }
            else if(i%4==3){
                c++;
            }
        }
    }
    printf("%d\n%d\n%d\n%d",a,b,c,d);
}