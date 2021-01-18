
#include <iostream>

using namespace std;

int dump() {
    int n;
    struct gl{
        int x,y;
        int score=-1;
        bool recy= false;
    };
    scanf("%d",&n);
    gl data[n];
    int up,down,left,right;
    int a=0,b=0,c=0,d=0,e=0;
    for(int i=0;i<n;i++){
        scanf("%d %d",&data[i].x,&data[i].y);
    }
    for(int j=0;j<n;j++){
        up=0,down=0,left=0,right=0;
        int score=0;
        for(int t=0;t<n;t++){
            //垃圾点上方有垃圾
            if(data[j].x==data[t].x&&data[j].y==data[t].y-1){
                up=1;
            }
            if(data[j].x==data[t].x&&data[j].y==data[t].y+1){
                down=1;
            }
            if(data[j].x==data[t].x+1&&data[j].y==data[t].y){
                left=1;
            }
            if(data[j].x==data[t].x-1&&data[j].y==data[t].y){
                right=1;
            }

            if(data[j].x==data[t].x+1&&data[j].y==data[t].y+1){
                score++;
            }
            if(data[j].x==data[t].x+1&&data[j].y==data[t].y-1){
                score++;
            }
            if(data[j].x==data[t].x-1&&data[j].y==data[t].y+1){
                score++;
            }
            if(data[j].x==data[t].x-1&&data[j].y==data[t].y-1){
                score++;
            }

        }
        if(up==1&&down==1&&left==1&&right==1){
            data[j].recy= true;
            data[j].score=score;

        }
    }
    for(int f=0;f<n;f++){
        if(data[f].score==0){a++;}
        if(data[f].score==1){b++;}
        if(data[f].score==2){c++;}
        if(data[f].score==3){d++;}
        if(data[f].score==4){e++;}
    }
    printf("%d\n%d\n%d\n%d\n%d",a,b,c,d,e);
}
