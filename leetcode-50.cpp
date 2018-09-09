#include <iostream>

using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        if(x==0.0)return 0.0;
        if(n==0)return 1.0;
        if(n==1)return x;
        if(n==-1)return 1/x;
        if(n<0){
            x = 1/x;
            return n%2==0?myPow(x*x,-(n/2)):myPow(x*x,-(n/2))*x;
        }
        //cout<<typeid(x).name()<<endl;
        return nn%2==0?myPow(x*x,n/2):myPow(x*x,n/2)*x;
    }
};

int main(){
    Solution solu;
    double x;
    int n;
    while(cin>>x>>n){
        cout<<solu.myPow(x,n)<<endl;
    }
}