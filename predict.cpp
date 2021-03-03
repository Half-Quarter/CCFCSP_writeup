#include<iostream>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
    int total=0;
    int weight=0;
    int score=0;
    for(int i=0;i<n;i++){
    	scanf("%d %d",&weight,&score);
    	int temp=weight*score;
    	total = total+temp;
	}
	if(total<0){
		total = 0;
	}
	cout<<total;
}