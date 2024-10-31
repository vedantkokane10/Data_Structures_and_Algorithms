/*
Longest K unique characters substring

Given a string s, you need to print the size of the longest possible substring with exactly k unique characters. If no possible substring exists, print -1.

Examples:
Input:
s = "aabacbebebe", k = 3
Output: 7
Explanation: 
"cbebebe" is the longest substring with 3 distinct characters.

Input: 
s = "aaaa", k = 2
Output: -1
Explanation: 
There's no substring with 2 distinct characters.

Input:
s = "aabaaab", k = 2
Output: 7
Explanation: 
"aabaaab" is the longest substring with 2 distinct characters.


*/


int longestKSubstr(string s, int k) {
    unordered_map<char,int> mp;
    int i = 0;
    int j = 0;
    int ans = -1;
    while(j < s.size()){
        mp[s[j]]++;
        while(mp.size() > k){
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
        }
        if(mp.size() == k){
            ans = max(ans,j-i+1);
        }
        j++;
    }
    return ans;
}
