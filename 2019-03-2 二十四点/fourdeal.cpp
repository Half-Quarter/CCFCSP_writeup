#include <stack>
#include <string>
#include <iostream>
#include <queue>

//#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> num;
    queue<int> res;
    int tt;
    int count = 0;
    scanf("%d",&tt);
    string fs;
    for (int i = 0; i < tt; i++) {
        cin >> fs;
        for (int j = 0; j < fs.length(); j++) {
            if (fs[j] - '0' >= 0 && fs[j] - '0' <= 9) {
                num.push(fs[j]-'0');
            }
            else if(fs[j]=='-'){
                num.push((-1)*(fs[j+1]-'0'));
                j++;
            }
            else if(fs[j]=='x'){
                int temp = num.top();
                int mult = temp * (fs[j+1]-'0');
                num.pop();
                num.push(mult);
                j++;
            }
            else if(fs[j]=='/'){
                int temp = num.top();
                int mult = temp / (fs[j+1]-'0');
                num.pop();
                num.push(mult);
                j++;
            }

        }
        while(!num.empty()){
            count = count + num.top();
            num.pop();
        }
        res.push(count);
        count = 0;
    }
    while(!res.empty()){
        if(res.front()!=24){
            cout<< "No" <<endl;
        } else if(res.front()==24){
            cout<<"Yes"<<endl;
        }
        res.pop();
    }
    return 0;
}