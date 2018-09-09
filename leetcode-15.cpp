#include <vector>
#include <iostream>
using namespace std;


class Solution{
public:
    vector< vector<int> > threeSum(vector<int> &num) {
        vector<int> vec(3);
        vector< vector<int> > result;
        // 1.排序
        sort(num.begin(), num.end());
        int sum;
        int len = num.size();
        // 2.拿出第一个数，转化为两数和问题。注意外层循环到倒数第三个数即可
        for(int i = 0; i < len-2; i++) {
            sum = 0 - num[i];
            vec[0] = num[i];
            // 3.两数和问题
            for(int j = i+1, k = len-1; j < k;) {
                if(num[j] + num[k] == sum) {
                    vec[1] = num[j++];
                    vec[2] = num[k--];
                    result.push_back(vec);
                    // 根据题目要求，跳过重复元素
                    while(j < k && num[j] == num[j-1]) 
                        j++;
                    while(j < k && num[k] == num[k+1])
                        k--;
                }
                else if(num[j] + num[k] < sum)
                    j++;
                else 
                    k--;
            }
            while(i < len-2 && num[i+1] == num[i])
                i++;
        }
        return result;
    }
};

int main(){
    int nums[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution solu;
    vector<int> vecs(nums,nums+15);
    vector<vector<int> > vec = solu.threeSum(vecs);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}