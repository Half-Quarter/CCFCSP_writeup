#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <sstream>
#include <map>
#include <stack>

using namespace std;

struct ball{
    int place;
    bool statu= true;//默认正向
};
int collball() {
    int totalball,length,time;
    scanf("%d %d %d",&totalball,&length,&time);
    ball b[totalball];
    for(int in=0;in<totalball;in++){
        cin>>b[in].place;
    }
    for(int t=0;t<time;t++){
        //位置变化，前进或后退状态变化
        for(int i=0;i<totalball;i++){
            if(b[i].statu){
                if(b[i].place==length){
                    b[i].statu= false;
                    continue;
                }
                b[i].place++;
                if(b[i].place==length){
                    b[i].statu= false;
                }
            }
            else if(!b[i].statu){
                if(b[i].place==0){
                    b[i].statu= true;
                    continue;
                }
                b[i].place--;
                if(b[i].place==0){
                    b[i].statu= true;
                }
            }
        }
        //判断碰撞
        for(int u=0;u<totalball;u++){
            for(int v=0;v<totalball;v++){
                //有可能出现同相碰撞？
                if(b[v].place == b[u].place&&u!=v){
                    b[u].statu = !b[u].statu;
                }
            }
        }
    }

    for(int j=0;j<totalball;j++){
        cout<<b[j].place<<" ";
    }
}
