#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len==0||len==1)return len;
        int i,j;
        i = j =0;
        int max_len = 0;
        while(i<len&&j<len){
            j++;
            int pos = s.find(s[j],i);
            //cout<<"pos = "<<pos<<"max_len = "<<max_len<<endl;
            if(pos==-1)continue;
            if(pos!=j){
                i = pos+1;
                //max_len = max(max_len,j-i+1);
            }
            max_len = max(max_len,j-i+1);
        }
        return max_len;
    }
};

int main(){
    Solution solu;
    cout<<solu.lengthOfLongestSubstring("")<<endl;
}