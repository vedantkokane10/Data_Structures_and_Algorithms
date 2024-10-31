/*
1358. Number of Substrings Containing All Three Characters

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c 
are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:
Input: s = "abc"
Output: 1


Approach -
lets say I am iterating the string and i am at index - 4
01234567
bbbacbac
now till index 4 we have all abc characters so minimum index at which we find abc 
is at index 2, so we can have strings bac, bbac, bbbac i.e 3 strings 
By this logic we need to iterate over the string update mp['a'] or b or c values (index)
everytime and then need to find minimum index from which abc is valid and check no of characters to its left
for example for index 'i' am at index - 4 we find that bac from index 2 to index 4 so by that logic we have 2 characters at left of minimum string
so we can add minIndex + 1 to our answer everytime we found valid abc substring.

*/

int numberOfSubstrings(string s) {
    int ans = 0;
    unordered_map<char,int> mp;
    mp['a'] = -1;
    mp['b'] = -1;
    mp['c'] = -1;
    for(int i=0;i<s.size();i++){
        mp[s[i]] = i;
        if(mp['a'] != -1 && mp['b'] != -1 && mp['c'] != -1){
            int minIndex = min({mp['a'],mp['b'],mp['c']});
            ans += (minIndex + 1); 
        }
    }
    return ans;
}
