#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <sstream>
#include <map>
#include <stack>

using namespace std;
//元素结构
struct element{
    string ename;
    int count;
    int rootcount=1;
};
//化学式(嵌套层数)
struct formula{
    string fname;
};
//括号角标倍数
struct arcMult{
    int mp;
    int mark;
};
//字符串转int
int strToInt(string &instr){
    int outint;
    stringstream ss;
    ss << instr;
    ss >> outint;
    return outint;
}
//队列清空
void clear(queue<char> &q){
    queue<char> empty;
    swap(empty,q);
}
//分割提取队列中的某个化学式
string poq(queue<char> &q){
    string back;
    while(!q.empty()){
        char t=q.front();
        q.pop();
        back = back + t;
    }
    return back;
}
//判断字符串是不是纯数字（提取系数）
bool isStrDigit(string &str){
    for(size_t i=0;i<str.size();i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}
//比较等式左右两边元素数量和种类是否相等
bool maperCompare(map<string,int> &mp1,map<string,int>&mp2) {
    map<string, int>::iterator it1 = mp1.begin();

    if (mp1.size() != mp2.size()) {
        return false;
    }
    while (it1 != mp1.end()) {
        map<string, int>::iterator it2 = mp2.find(it1->first);
        if (it2 != mp2.end()) {
            if (it2->second != it1->second) {
                return false;
            }
        } else {
            return false;
        }
        it1++;
    }
    return true;
}
//分离数字和字母
element splitStr(string &str,int ratio){
    element test;
    queue<char>temp_char;
    string name;
    for(size_t t=0;t<str.size();t++){
        temp_char.push(str[t]);
        if(str[t]==')'){
            test.ename=')';
            clear(temp_char);
        }
        if (isupper(str[t]) || islower(str[t])) {
            if (islower(str[t + 1])) {
                continue;
            }
            string name = poq(temp_char);
            test.ename=name;
            clear(temp_char);
        }
        test.count = 1 * ratio;
        if (isdigit(str[t])) {
            if (isdigit(str[t + 1])) {
                continue;
            }
            int counta = 1;
            string str_ratio = poq(temp_char);
            counta = strToInt(str_ratio);
            test.rootcount=counta;
            test.count=counta*ratio;
            clear(temp_char);
        }
    }
    return test;
}

int chemisty() {
    int total;
    scanf("%d",&total);
    bool result[total];
    for(int t=0;t<total;t++) {
        string test;
        cin>>test;
        //总方程式
        queue<char> chem;
        //化学式
        stack<string> forstack;
        //换边；
        bool turn = false;
        //括号嵌套
        int layer=0;
        //括号开闭
        bool open= false;
        queue<arcMult> multi_ratio;
        map<string, int> left_el;
        map<string, int> right_el;
        map<string, int>::iterator iter1;
        int marker=0;
        int ratio=1;
        for (size_t i = 0; i < test.size(); i++) {
            chem.push(test[i]);
//如果为数字，数字应该连续
            if (isdigit(test[i])) {
                if (isdigit(test[i + 1])) {
                    continue;
                }
                if(isdigit(chem.front())){
                    string rest = poq(chem);
                    int rat = strToInt(rest);
                    ratio =rat;
                    continue;
                }
                string rest = poq(chem);
                forstack.push(rest);
                clear(chem);
            }
//遇到大写字母 后有数字则连续，后有小写字母则连续
            if (isupper(test[i])) {
                if (isdigit(test[i + 1])) {
                    continue;
                }
                if (islower(test[i + 1])) {
                    continue;
                }
                string rest = poq(chem);
                clear(chem);
                forstack.push(rest);
            }

//遇到小写字母 后面只有可能接数字
            if (islower(test[i])) {
                if (isdigit(test[i + 1])) {
                    continue;
                }
                string rest = poq(chem);
                clear(chem);
                forstack.push(rest);
            }
//判断括号
            if(test[i]=='('){
                forstack.push("(");
                chem.pop();
            }
            if(test[i]==')'){
                if(isdigit(test[i+1])){
                    continue;
                }
                else{
                    forstack.push(")1");
                }
                clear(chem);
            }

            if (test[i] == '+' || test[i] == '=' || i == test.size() - 1 ) {
                int root_count = 1 ;
                stack<int> rnum;
                while (!forstack.empty()) {
                    string temp_str = forstack.top();
                    if (temp_str == "(") {
                        ratio = ratio/rnum.top();
                        rnum.pop();
                        forstack.pop();
                        continue;
                    }
                    element some_element = splitStr(temp_str, ratio);
                    if (some_element.ename == ")") {
                        ratio = some_element.count;
                        rnum.push(some_element.rootcount);
                        forstack.pop();
                        continue;
                    }
                    forstack.pop();
                    //判断等式左右
                    if (!turn) {
                        iter1 = left_el.find(some_element.ename);
                        if (iter1 != left_el.end()) {
                            left_el[some_element.ename] = iter1->second + some_element.count;
                        } else {
                            left_el.insert(pair<string, int>(some_element.ename, some_element.count));
                        }
                    } else {
                        iter1 = right_el.find(some_element.ename);
                        if (iter1 != right_el.end()) {
                            right_el[some_element.ename] = iter1->second + some_element.count;
                        }
                        right_el.insert(pair<string, int>(some_element.ename, some_element.count));
                    }
                }
                clear(chem);
                ratio=1;
            }
            if (test[i] == '=') {
                turn = true;
            }
        }
        result[t]=maperCompare(left_el,right_el);
    }
//循环体外
    for(int i=0;i<total;i++){
        if(result[i]){
            cout << "Y" << endl;
        }
        else{
            cout << "N" << endl;
        }
    }
}
