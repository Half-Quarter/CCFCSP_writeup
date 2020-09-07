#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <sstream>
#include <map>
#include <stack>

using namespace std;

void clearStack(stack<int> &s){
    stack<int>().swap(s);
}

int appletree2() {
    stack<int> at;
    int total;
    int tota=0;
    int neigh=0;
    int totfall=0;
    scanf("%d",&total);
    int totf[total];
    for(int i=0;i<total;i++){
        bool fall=false;
        int num;
        int oap;
        cin>>num;
        totf[i]=0;
        for(int j=0;j<num;j++){
            //第一个数字一定是第一次统计的苹果数量
            if(j==0) {
                cin>>oap;
                at.push(oap);
                continue;
            }
            cin>>oap;
            //如果是大于零的数字是重新统计苹果数量
            if(oap>0){
                if(at.top()==oap){
                    continue;
                }
                totf[i]=1;
                at.pop();
                at.push(oap);
            }
            if(oap<=0){
                int newnum = at.top()+oap;
                at.pop();
                at.push(newnum);
            }
        }
        tota=tota+at.top();
        clearStack(at);
    }

    for(int t=0;t<total;t++){
        totfall=totfall+totf[t];
        if(t==0){
            if(totf[t]==1&&totf[total-1]==1&&totf[t+1]==1){
                neigh++;
            }
        }
        else if(t==total-1){
            if(totf[t]==1&&totf[t-1]==1&&totf[0]==1){
                neigh++;
            }
        }
        else{
            if(totf[t]==1&&totf[t-1]==1&&totf[t+1]==1){
                neigh++;
            }
        }
    }

    printf("%d %d %d",tota,totfall,neigh);
}
