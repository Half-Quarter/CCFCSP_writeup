#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int freetime() {
    int n;
    int total=0;
    scanf("%d",&n);
    vector<int> v;
    for(int i=0;i<n;i++){
        int begin,end;
        scanf("%d %d", &begin, &end);
        for (; begin < end; begin++) {
            v.push_back(begin);
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    int pivot=0;
    for(int j=0;j<n;j++){
        int begin,end;
        scanf("%d %d", &begin, &end);
        for (; begin < end; begin++) {
            while(pivot < v.size()){
                if(begin==v[pivot]){
                    total++;
                    pivot++;
                    break;
                }
                else if(begin>v[pivot]){
                    pivot++;
                }
                else if(begin<v[pivot]){
                    break;
                }
            }
        }
    }
    cout<<total;
}
