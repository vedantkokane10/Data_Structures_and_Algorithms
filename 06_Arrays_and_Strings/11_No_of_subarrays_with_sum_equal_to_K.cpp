/*
Leetcode - 560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

*/

int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    unordered_map<int,int> mp;
    int cnt = 0;
    mp[0] = 1;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        if(mp.find(sum - k) != mp.end()){
            cnt += mp[sum-k];
        }
        mp[sum]++;
    }
    return cnt;
}
