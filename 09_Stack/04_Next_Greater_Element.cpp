/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, 
then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
*/

/*
Approach - Maintain a monotoinic stack which will hold elements in increasing order and also maintain a map to store
next greater element mapping. First put last element of 2nd array and traverse from behind in 2nd array if current iterated
element is smaller  than stack's top then stack's top is next greater element to current iterated element do mapping.
If current iterated element is bigger than stack's top element then we need to pop elements from stack until we found a
element in the stack such that it is greater than the current iterated element if we found then that element is mapped in map
else -1 is assgined while mapping the current iterated element since we don't have any element greater than current iterated element.

*/


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s1;
    unordered_map<int,int> mp;
    vector<int> ans;
    int n = nums2.size();
    s1.push(nums2[n-1]);
    for(int i=n-1;i>=0;i--){
        if(nums2[i] < s1.top()){
            mp[nums2[i]] = s1.top();
            s1.push(nums2[i]);
        }
        else{
            while(!s1.empty() && nums2[i] >= s1.top()){
                s1.pop();
            }

            if(s1.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]] = s1.top();
            }

            s1.push(nums2[i]);
        }
    }

    for(auto x:nums1){
        ans.push_back(mp[x]);
    }

    return ans;
}
