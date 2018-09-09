#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> mapping;
        mapping.push_back("abc");
        mapping.push_back("def");
        mapping.push_back("ghi");
        mapping.push_back("jkl");
        mapping.push_back("mno");
        mapping.push_back("pqrs");
        mapping.push_back("tuv");
        mapping.push_back("wxyz");

        string str;
        int i=0;
        L1:
        for(;i<digits.length();){
            int idx = digits[i]-'0'-2;
            for(int j=0;j<mapping[idx].length();j++){
                str.push_back(mapping[idx][j]);
                i++;
                goto L1;
                result.push_back(str);
                cout<<" str: " <<str<<endl;
                str.pop_back();
                i--;
            }
        }

        return result;
    }
};

int main(){

    Solution solu;
    solu.letterCombinations("23");
    return 0;

}