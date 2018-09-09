#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0){
            if(nums2.size()%2==0)return float(nums2[nums2.size()/2-1]+nums2[nums2.size()/2])/2;
            else return nums2[nums2.size()/2];
        }
        if(nums2.size()==0){
            if(nums1.size()%2==0)return float(nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/2;
            else return nums1[nums1.size()/2];
        }
        int len = nums1.size()+nums2.size();
        auto i = 0,j = 0;
        int cnt = 0;
        int isodd = len%2==0?0:1;
        float median = 0;
        //if(len==2) return float(nums1[0]+nums2[0])/2;
        while(i<nums1.size()&&j<nums2.size()){
            if(isodd&&cnt==(len-1)/2){
                median = nums1[i]<nums2[j]?nums1[i]:nums2[j];
                break;
            }
            cout<<"i = "<<i<<"j = "<<j<<"m = "<<median<<endl;;

            if(isodd==0&&cnt==len/2-1){
                vector<int> tmp;
                tmp.push_back(nums1[i]);
                tmp.push_back(nums2[j]);
                if(i+1<nums1.size()){
                    tmp.push_back(nums1[i+1]);
                }
                if(j+1<nums2.size()){
                    tmp.push_back(nums2[j+1]);
                }
                sort(tmp.begin(),tmp.end());
                cout<<"@"<<tmp[0]<<" "<<tmp[1]<<endl;
                median = float(tmp[0]+tmp[1])/2;
                break;
            }
            if(nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
            cnt++;
        }
        return median;
    }

};

int main(){
    Solution solu;
    int num1[] = {2,2,2,2};
    int num2[] = {2,2,2};
    vector<int> nums1(num1,num1+4);
    vector<int> nums2(num2,num2+3);
    cout<<solu.findMedianSortedArrays(nums1,nums2)<<endl;
}