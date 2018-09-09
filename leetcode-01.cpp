#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> vec(2);
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(nums[i]+nums[j]==target){
                    vec[0]=i;
                    vec[1]=j;
                    return vec;
                }
            }
        }
        return vec;
    }
};

int main(){
    int nums[] = {2,7,11,15};
    int target = 9;
    vector<int> vec(nums,nums+4);
    Solution solu;
    vector<int> r = solu.twoSum(vec,target);
    cout<<r[0]<<" "<<r[1]<<endl;
    return 0;

}