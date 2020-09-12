//
// Created by zhan on 2020/9/9.
//

#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <sstream>
#include <map>
#include <stack>

using namespace std;

int aliveOne(int *peo,int size){
    int totalalive=0;
    int aliveMan;
    for(int i=0;i<size;i++){
        if (peo[i]==1){
            totalalive++;
            aliveMan=i;
        }
    }
    if(totalalive==1){
        return aliveMan;
    }
    else {
        return -1;
    }
}
int game() {
    int n,k;
    scanf("%d %d",&n,&k);
    int people[n];
    for(int j=0;j<n;j++){
        people[j]=1;
    }
    int nownum=1;
    int i=0;
    while(aliveOne(people,n)==-1){
        //报数 如果淘汰了就不用报数了
        //人的编号先发生改变
        if(i==n-1){
            i=0;
        }
        else{
            i++;
        }
        if(people[i]==0){
            continue;
        }
        //报的数发生改变，并判断这个人是否被淘汰
        nownum++;
        if(nownum%10==k||nownum%k==0){
            people[i]=0;
        }
    }

    if(aliveOne(people,n)==0){
        cout<<n;
    }
    else{
        cout<<aliveOne(people,n)+1;
    }
}
