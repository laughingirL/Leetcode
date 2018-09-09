#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;

        string str(s.length(),'#');
        int len = s.length();
        int k = 0;
        int base = 0;
        for(int i=0;i<len;){
            if(base>=len){
                base=0;
                k++;
            }
            if(k==0||k==numRows-1){
                str[i]= s[base+k];
                //i++;
                //cout<<"0 "<<i<<" "<<str[i]<<endl;
                i++;
            }else{
                
                //i = i+2;
                //cout<<"!0 "<<i<<" "<<str[i]<<endl;
                if(base + 2*numRows-2-k<=len-1){
                    str[i]= s[base+k];
                    str[i+1]= s[base+2*numRows-2-k];
                    //cout<<"!0 "<<i<<" i+2 "<<str[i]<<endl;
                    //cout<<"!0 "<<i<<" "<<str[i]<<endl;
                    //cout<<"!0 "<<i+1<<" "<<str[i+1]<<endl;
                    i = i+2;
                }else if(base+k<=len-1){
                    str[i]= s[base+k];
                    //cout<<"!0 "<<i<<" i+1 "<<str[i]<<endl;
                    //cout<<"base+k: "<<base+k<<endl;
                    i++;
                }
            }
            //if(i==len-1)cout<<str[i]<<endl;
            
            base += 2*numRows-2;
        }
        
        return str;
    }
};

int main(){
    string s = "PAYPALISHIRING";
    int numRows = 7;
    Solution solu;
    cout<<solu.convert(s,numRows)<<endl;
    return 0;

}