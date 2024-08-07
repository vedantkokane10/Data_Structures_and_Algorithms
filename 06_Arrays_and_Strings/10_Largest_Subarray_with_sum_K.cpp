/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum K.

Examples:
Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8 , k = 0
Output: 5
Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.

Input: arr[] = {2,10,4}, n = 3 , k = 0
Output: 0
Explanation: There is no subarray with 0 sum. 

Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6 , k = 0
Output: 5
Explanation: The subarray is 0 -4 3 1 0.
*/




/*
Approach - Iterate calculate sum if sum equls to k then update max length with i+1 else if current sum is present is map then update length with difference of i
and mapped sum index else if sum not present in map put it along with the index.
*/

int maxLen(vector<int>& arr, int n,int k) {
    unordered_map<int,int> mp;
    int sum = 0;
    int mx = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum == k){
            int currentLength = i+1;
            mx = max(mx,currentLength);
        }
        else{
            if(mp.find(sum) != mp.end()){
                int currentLength = i - mp[sum] ;
                mx = max(mx,currentLength);
            }
            else{
                mp[sum] = i;
            }
        }
    }
    return mx;
}
