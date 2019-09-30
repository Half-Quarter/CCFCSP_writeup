#include <stack>
#include <iostream>
//#include<bits/stdc++.h>
    using namespace std;
    int main(){
       int n;
       scanf("%d",&n);
       int bef[n],aft[n];
        for (int i = 0; i < n; i++) {
            cin >> bef[i];
         }
        for(int i=0; i < n;i++){
            if(i==0) aft[i]=(bef[i]+bef[i+1])/2;
            else if(i==n-1) aft[i]=(bef[i]+bef[i-1])/2;
            else  aft[i]=(bef[i]+bef[i-1]+bef[i+1])/3;
            printf("%d ",aft[i]);
        }
    }
