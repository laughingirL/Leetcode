#include <string> 
#include <iostream>
#include <limits.h>
using namespace std;

class Solution{
public:
    int myAtoi(string str){
        int n = str.length();
        int i=0,j;
        int flag = 0,exceed = 0; 
        long result = 0;
        while(str[i]==' '&& i<n)i++;
        //cout<<"i = "<<i<<endl;
        if(i==n){
            result = 0;
        }else{
            if(!(str[i]>='0'&&str[i]<='9')){
                if(str[i]=='-'){
                    flag = 1;
                    i++;
                    //cout<<"-"<<i<<endl;
                }else if(str[i]=='+'){
                    i++;
                }else{
                    //cout<<"wrong"<<endl;
                    return 0;
                }
            }
            while(str[i]=='0'&& i<n)i++;
            j = i;
            while(str[j]>='0'&&str[j]<='9')j++;
            if(j==i){
                result = 0;
            }else{
                if(j-i>10)exceed = 1;
                for(;i<j;i++){
                    result = result*10 + str[i]-'0';
                }
            }  
            if(flag)result = -result;  
        }
        if(exceed){
            if(flag)result = INT_MIN;
            else result = INT_MAX;
        }else{
            if(result<long(INT_MIN))result = INT_MIN;
            if(result>INT_MAX)result = INT_MAX;
        }
        return result;
    }
};

int main(){
    Solution solu;
    string s = "123fg";
    while(cin>>s){
        int result = solu.myAtoi(s);
        cout<<result<<endl;
    }
    
}