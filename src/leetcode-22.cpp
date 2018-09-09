#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        char ch[2] = {'(',')'};
        int num1=3,num2=3;
        stack<char> stk;
        while(num1>=0&&num2>=0){
            if(stk.empty()){
                stk.push(ch[0]);
                num1--;
            }else{
                if(stk.top()==ch[1]){
                    stk.push(ch[0]);
                    num1--;
                }else{
                    int k=0;
                }
            }
        }
    }
    string generate_a_sam(int num1,int num2,stack<char>&stk){
        return "PL";
    }
};