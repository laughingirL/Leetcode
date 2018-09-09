#include <stack>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;
        int len = s.length();
        for(int i = 0; i< len; i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{')cs.push(s[i]);
            else{
                if(cs.empty())return false;
                else{
                    //cout<<"s[i]: "<<s[i]<<" top: "<<cs.top()<<endl;
                if(s[i]==')'){
                    if(cs.top()=='('){
                        cs.pop();
                        continue;
                    }else{
                        //cout<<1<<endl;
                        return false;
                    }
                }
                if(s[i]==']'){
                    if(cs.top()=='['){
                        cs.pop();
                        continue;
                    }else{
                        //cout<<2<<endl;
                        return false;
                    }
                }
                if(s[i]=='}'){
                    if(cs.top()=='{'){
                        cs.pop();
                        continue;
                    }else{
                        //cout<<3<<endl;
                        return false;
                    }
                }
                }
                
            }
        }
        if(cs.empty()){
            return true;
        }else return false;
    }
};

int main(){
    Solution solu;
    string s = "()";
    while(cin>>s){
        int flag = solu.isValid(s);
        cout<<"result: "<<flag<<endl;
    }
    
}