
#include <iostream>

using namespace std;

int line(){
    int point,line;
    scanf("%d %d",&point,&line);
    int fx,fy;
    char ft;
    scanf("%d %d %c",&fx,&fy,&ft);
    int sx[point],sy[point];
    char st[point];
    sx[0]=fx;
    sy[0]=fy;
    st[0]=ft;
    //点初始化
    for(int i=1;i<point;i++){
        scanf("%d %d %c",&sx[i],&sy[i],&st[i]);
    }
    //线初始化
    int l1,l2,l3;
    char type=st[0];
    int up=0;
    bool res[line];
    for(int j=0;j<line;j++){
        res[j]= true;
        scanf("%d %d %d",&l1,&l2,&l3);
        if(l1+l2*sx[0]+l3*sy[0]>0){
            up=1;
        }
        if(l1+l2*sx[0]+l3*sy[0]<0){
            up=0;
        }
        else if(l1+l2*sx[0]+l3*sy[0]==0){
            res[j]= false;
        }
        for(int k=1;k<point;k++){
            int mult= l1+l2*sx[k]+l3*sy[k];
            if(mult==0){
                res[j]= false;
            }
            else{
                if(up==1){
                    if(mult>0&&st[k]!=type){
                        res[j]= false;
                    }
                    if(mult<0&&st[k]==type){
                        res[j]= false;
                    }
                }
                if(up==0){
                    if(mult<0&&st[k]!=type){
                        res[j]= false;
                    }
                    if(mult>0&&st[k]==type){
                        res[j]= false;
                    }
                }

            }
        }
    }
    for(int z=0;z<line;z++){
        if(res[z]){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}