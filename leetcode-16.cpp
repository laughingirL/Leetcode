#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        //sort(nums.begin(),nums.end());
        int result = 1000000;
        for(int i=0;i<len;i++){
            for(int j = i+1; j < len ; j++){
                for(int k = j + 1 ; k < len ; k++){
                    int tmp = nums[i]+nums[j]+nums[k];
                    int diff = abs(tmp-target);
                    if(diff==0)return tmp;
                    else if(diff<abs(result-target))result = tmp;
                }
            }
        }
        return result;
        
    }
};

int main()
{
    int nums[] = {-1,2,1,-4};
    vector<int> num(nums,nums+4);
    Solution solu;
    cout<<solu.threeSumClosest(num,1)<<endl;
}