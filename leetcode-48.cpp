#include <iostream>
#include <vector>
using namespace std;
/**
static const auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
*/
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        rotate_out(matrix,1);
    }
    void rotate_out(vector<vector<int> >&matrix,int idx){
        int len = matrix.size();
        if(idx==len/2+1)return;
        
        int begin = idx-1;
        int end = len-idx;
        int length = end-begin+1;
        for(int i=0;i<length-1;i++){
            int tmp = matrix[end-i][begin];
            matrix[end-i][begin] = matrix[end][end-i];
            matrix[end][end-i] = matrix[begin+i][end];
            matrix[begin+i][end] = matrix[begin][begin+i];
            matrix[begin][begin+i] = tmp;
        }
        rotate_out(matrix,idx+1);
    }
};

int main(){
    int n=4;
    int num1[] = {5,1,9,11};//{1,2,3};
    int num2[] = {2,4,8,10};//{4,5,6};
    int num3[] = {13,3,6,7};//{7,8,9};
    int num4[] = {15,14,12,16};
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(num1,num1+n));
    matrix.push_back(vector<int>(num2,num2+n));
    matrix.push_back(vector<int>(num3,num3+n));
    matrix.push_back(vector<int>(num4,num4+n));
    cout<<"before: "<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    Solution solu;
    solu.rotate(matrix);
    cout<<"after: "<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}