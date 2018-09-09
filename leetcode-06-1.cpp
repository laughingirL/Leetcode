#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string str(s.length(),'\0');
        int N = 1000000;
        int len = s.length();
        int flag[N];
        for(int i=0;i<len;i++){
            flag[i] = 0;
        }
        if(numRows==1)return s;
        for(int i=0;i<len;i++){
            int idx = i%(2*numRows-2);
            if(idx < numRows){
                flag[i] = idx;
            }else{
                flag[i] = 2*numRows-2-idx;
            }
        }
        int k = 0;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<len;j++){
                if(flag[j]==i)str[k++]=s[j];
            }
        }
        return str;
    }
};

int main(){
    string s = "A";//"PAYPALISHIRING";
    int numRows = 1;
    Solution solu;
    cout<<solu.convert(s,numRows)<<endl;
    return 0;

}