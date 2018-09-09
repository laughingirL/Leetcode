#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        char ones[] = {'I','X','C','M'};
        char fives[] = {'V','L','D','#'};
        int sub = 1000;
        string roman;
        int i=3;
        while(sub>=1){
            int flag = int(num/sub);
            if(flag!=0){
                if(flag<4){
                    while(flag--){
                        roman.push_back(ones[i]);
                    }
                }else if(flag==4){
                    roman.push_back(ones[i]);
                    roman.push_back(fives[i]);
                }else if(flag<9){
                    roman.push_back(fives[i]);
                    while((flag--)>5)roman.push_back(ones[i]);
                }else{
                    roman.push_back(ones[i]);
                    roman.push_back(ones[i+1]);
                }
            }
            num %= sub;
            sub /= 10;
            i--;
            
        }
        return roman;
    }
};

int main(){

    int num;
    Solution solu;
    while(cin>>num){
        cout<<solu.intToRoman(num)<<endl;
    }
    return 0;
}