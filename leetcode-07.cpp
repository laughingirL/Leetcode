#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ispositive = x<0?0:1;
        long result = 0;
        int tmp = x;
        while(1){
            result = result*10 + tmp%10;
            tmp /= 10;
            if(tmp==0)break;
        }
        if(result>2147483647||result < -2147483648)result = 0;
        return result;
    }
};

int main()
{
    Solution solu;
    int x;
    while(cin>>x){
        cout<<solu.reverse(x)<<endl;
    }
    return 0;
    
}