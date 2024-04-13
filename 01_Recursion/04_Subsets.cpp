/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

                    []
           /                    \
          [1]                   []
        /     \              /     \
      [1, 2]  [1]           [2]    []
     /    \     |          /   \   / \
  [1,2,3] [1,2] [1]       [2,3] [2] []
   ...   ...   ...        ...   ...


Approach - 
1. Take or don't take
2. take and move to next index
3. don't take and move to next index
4. for base case --> if ind >= nums.size() simply push sample array in answer array.

*/

/*
Given an integer array nums of unique elements, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

*/

void helper(int i,vector<int> &nums,vector<vector<int>> &ans,vector<int> &sample){
    if(i == nums.size()){
        ans.push_back(sample);
        return;
    }
    if(i > nums.size()){
        return;
    }
    sample.push_back(nums[i]);
    helper(i+1,nums,ans,sample);
    sample.pop_back();
    helper(i+1,nums,ans,sample);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> sample;
    helper(0,nums,ans,sample);
    return ans;
}
