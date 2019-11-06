#include <stack>
//#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,y,g;
    scanf("%d %d %d",&r,&y,&g);
    int n;
    scanf("%d",&n);
    int ste,t;
    long long timepass=0;
    int period,realt;
    for(int i=0;i<n;i++){
        scanf("%d %d",&ste,&t);
        if(i==0){
            period = 0;
        }
        else {
            period = timepass % (r+y+g);
        }
        realt = t - period;
        if(ste==0){
            timepass = timepass + t;
        }
            //原为红灯
        else if(ste==1){
            //仍为红灯
            if(realt >0 ){
                timepass = timepass + realt;
            }
                //变为黄灯
            else if(abs(realt)>= g && abs(realt)< g+y){
                timepass = timepass +y - g - abs(realt);
            }
                //一周期内又变为红灯
            else if(abs(realt)>=g+y){
                timepass =timepass +r - (abs(realt)-g-y);
            }
        }
            //原为黄灯
        else if(ste==2){
            //仍为黄灯
            if(realt >0){
                timepass = timepass +realt + r;
            }
            //变为红灯
            if(realt <= 0 && realt > (-1)*r && abs(realt)<g+r){
                timepass = timepass +r - abs(realt);
            }
            //又变黄灯
            if(abs(realt) >=g+r){
                timepass = timepass + r+y+g - abs(realt) + r;
            }
        }
            //原为绿灯
        else if(ste==3){
            //变为黄灯
            if(realt>0){
                timepass = timepass + 0;
            }
            else if(realt <= 0 && abs(realt)<y){
                timepass = timepass + y  - abs(realt) + r;
            }
            else if(abs(realt)>=y && abs(realt)< y+r){
                timepass = timepass + y+r - abs(realt);
            }
        }
    }
    printf("%d",timepass);
    return 0;
}
