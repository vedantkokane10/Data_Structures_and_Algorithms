/*
Given a string s, return the maximum number of unique substrings that the given string can be split into.
You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. 
However, you must split the substrings such that all of them are unique.
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.

Example 2:
Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].

Example 3:
Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.

*/


int ans = 0;
void helper(int ind,string str,unordered_map<string,int> mp){
    if(ind == str.size()){
        int currentSize = mp.size();
        ans = max(ans,currentSize);
        return;
    }
    string sub = "";
    for(int i=ind;i<str.size();i++){
        sub += str[i];
        if(mp.find(sub) == mp.end()){
            mp[sub] = 1;
            helper(i+1,str,mp);
            mp.erase(sub);
        }
    }
    
}
int maxUniqueSplit(string str) {
    unordered_map<string,int> mp;
    helper(0,str,mp);
    return ans;
}
