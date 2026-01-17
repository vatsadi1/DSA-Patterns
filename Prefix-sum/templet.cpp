#include<iostream>
#include <vector>

using namespace std;

vector<int> buildPrefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);

    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

int main()
{
    return 0;
}