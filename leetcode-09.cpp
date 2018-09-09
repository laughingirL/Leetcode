#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int digit[20];
        int tmp =x,i=0;
        int length = 0;
        while(1){
            digit[i++] = tmp%10;
            tmp /= 10;
            if(tmp==0)break;
        }
        //for( int k =0;k<i;k++)cout<<digit[k];
        //cout<<endl;
        int j = 0;
        length = i;
        i--;
        while(digit[j]==digit[i]&&j<i){
            j++;
            i--;
        }
        if(j>=i)return true;
        else return false;
    }
};


int main(){
    Solution solu;
    int x;
    while(cin>>x){
        cout<<solu.isPalindrome(x)<<endl;
    }
    return 0;
}