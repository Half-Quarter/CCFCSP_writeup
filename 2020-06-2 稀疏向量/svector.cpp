#include <iostream>
#include <vector>
using namespace std;

int svector()
{
    int n, a, b;
    int x, y;
    long long innerProduct = 0;
    cin >> n >> a >> b;
    vector< pair<int, int> > v1;
    for (int i = 0; i < a; i++) {
        cin >> x >> y;
        v1.push_back(make_pair(x, y));
    }
    int x1, y1;
    int pivot = 0;
    for (int j = 0; j < b; j++) {
        cin >> x1 >> y1;
        while (pivot < a) { //省时手段，如果已完成v1内元素的遍历则不进行循环
            if (v1[pivot].first == x1) { //匹配成功
                innerProduct += y1 * v1[pivot].second;
                pivot++; //进行下一个元素的匹配
                break;
            }
            else if (x1 < v1[pivot].first) //当前输入元素角标小于当前容器角标，相当于内积为0，忽略
                break;
            else /*if (x1 > v1[pivot].first)*/ //v1当前指向元素角标小于输入的，自加一再比较
                pivot++;
        }
    }
    cout << innerProduct << endl;
    return 0;
}
