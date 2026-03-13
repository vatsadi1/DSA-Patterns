// 724. Find Pivot Index
// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
#include<iostream>
#include<vector>
using namespace std;
int main()
{

    class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum = sum + nums[i];
        }

        int cs = 0;

        for(int i = 0;i<n;i++){
            int ls=cs;
            int rs = sum - cs - nums[i];
            if(ls == rs){
                return i;
            }
                cs +=nums[i];
            
        }
        return -1;
    }
};
    
}