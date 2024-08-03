/*
A swap is defined as taking two distinct positions in an array and swapping the values in them.
A circular array is defined as an array where we consider the first element and the last element to be adjacent.
Given a binary circular array nums,
return the minimum number of swaps required to group all 1's present in the array together at any location.

Example 1:
Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.

Example 2:
Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.

Example 3:
Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
*/

/*
Approach - Count no of ones first that will be the window size and then make a new array of size 2*n to handle circular condition
and apply sliding window where we count no of zeros and when we have window of size equal to total ones we how many zeros in window
and update the answer variable by selecting minimum between current answer value and zeros.
*/

int minSwaps(vector<int>& nums) {
    int ones = 0;
    int n = nums.size();
    vector<int> arr(2*n);
    for(int i=0;i<nums.size();i++){
        if(nums[i] == 1){
            ones++;
        }
        arr[i] = nums[i];
        arr[i+n] = nums[i];
    }
    int j = 0;
    int i = 0;
    int mn = INT_MAX;
    int zeros = 0;
    while(j < arr.size()){
        if(arr[j] == 0){
            zeros++;
        }
        while(j-i+1 == ones){
            mn = min(mn,zeros);
            if(arr[i] == 0){
                zeros--;
            }
            i++;
        }
        j++;
    }
    if(mn == INT_MAX){
        return 0;
    }
    return mn;
}

