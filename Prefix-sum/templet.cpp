// Vector revision

#include<iostream>
 #include<vector>
 using namespace std;

 void display(vector<int>&v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
 }
 int main()
 {
    int a;
    cout<<"Enter the value of a"<<endl;
    cin>>a;
    vector<int>vec;

      cout << "Enter " << a<< " elements:" << endl;
    for(int i = 0; i < a; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }

      // Pop last element
    if(!vec.empty()) {
        vec.pop_back();
    }

    cout << "After pop_back(): ";
    
    display(vec);
     return 0;
 }

// Basic Prefix Sum Template

vector<int> buildPrefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);

    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}
// 📌 Range Query Using Prefix Sum

int rangeSum(vector<int>& prefix, int L, int R) {
    if(L == 0) return prefix[R];
    return prefix[R] - prefix[L - 1];
}

// 🧩 Generic Template (MUST MEMORIZE)

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;  // Handles subarrays starting from index 0

    int currSum = 0, count = 0;

    for(int x : nums) {
        currSum += x;

        if(mp.count(currSum - k)) {
            count += mp[currSum - k];
        }

        mp[currSum]++;
    }
    return count;
}




// 303. Range Sum Query - Immutable

class NumArray {
public:
 vector<int>prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n);
        
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1] + nums[i];
        }
        
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefix[right];
        return prefix[right] - prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Two Sum


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
              vector<int> index;
        for(int i =0;i<nums.size();i++) {
        for(int j =i+1;j<nums.size();j++){
            if( nums[i] + nums[j] == target){
            index.push_back(i);
             index.push_back(j);
            return index;
            }
 }
 }
 return index;
 }
};
