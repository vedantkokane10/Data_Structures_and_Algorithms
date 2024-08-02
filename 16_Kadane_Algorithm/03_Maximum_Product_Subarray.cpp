/*
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

int maxProduct(vector<int>& nums) {
    int prefixProduct = 1;
    int maxPrefixProduct = INT_MIN;
    for(int i=0;i<nums.size();i++){
        prefixProduct = prefixProduct * nums[i];
        maxPrefixProduct = max(prefixProduct,maxPrefixProduct);
        if(prefixProduct == 0){
            prefixProduct = 1;
        }
    }

    long long suffixProduct = 1;
    long long  maxSuffixProduct = INT_MIN;
    for(int i=nums.size()-1;i>=0;i--){
        suffixProduct = suffixProduct * nums[i];
        maxSuffixProduct = max(suffixProduct,maxSuffixProduct);
        if(suffixProduct == 0){
            suffixProduct = 1;
        }
    }
    return max(maxPrefixProduct,maxSuffixProduct);
}
