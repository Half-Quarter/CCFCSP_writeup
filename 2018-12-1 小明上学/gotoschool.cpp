#include <stack>
#include <string>
#include <iostream>
#include <queue>

//#include<bits/stdc++.h>
using namespace std;

int main() {
    int r,y,g;
    scanf("%d %d %d",&r,&y,&g);
    int n;
    int count=0;
    scanf("%d",&n);
    int ste,t;
    for(int i=0;i<n;i++){
        scanf("%d %d",&ste,&t);
        if(ste==0){
            count = count + t;
        }
        else if(ste==1){
            count = count + t;
        }
        else if(ste==2){
            count = count + t + r;
        }
    }
    printf("%d",count);
}