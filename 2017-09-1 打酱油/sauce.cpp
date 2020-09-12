#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <sstream>
#include <map>
#include <stack>

using namespace std;

int sauce() {
    //从最优惠的开始算 先买五送2 再买三送1 再单买
    int n;
    scanf("%d",&n);
    int a = n/50;
    int b = (n%50)/30;
    int c = ((n%50)%30)/10;
    int result = 7*a+4*b+c;
    cout<<result;
}
