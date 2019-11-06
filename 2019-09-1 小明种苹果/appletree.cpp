#include <stack>
#include <iostream>
//#include<bits/stdc++.h>
    using namespace std;
    int main(){
    int a,b;
     scanf("%d %d",&a,&b);
     int tree[a];
     int apple[b];
     int dead[a];
     int toa=0,max=0;
     for(int i=0;i<a;i++){
         for (int j = 0; j < b+1; ++j) {
             cin >> apple[j];
             if (j != 0) {
                 toa = toa + abs(apple[j]);
             }

         }
         tree[i] = apple[0] - toa;
         dead[i] = toa;
         if(i==0){
             max = 0;
         }
         else if(toa>dead[i-1]&&i>0){
             max = i;
         }
         toa=0;
      }
    int totapp = 0;
    for(int i=0;i<a;i++){
        totapp = totapp + tree[i];
     }
    printf("%d %d %d",totapp,max+1,dead[max]);
    }
