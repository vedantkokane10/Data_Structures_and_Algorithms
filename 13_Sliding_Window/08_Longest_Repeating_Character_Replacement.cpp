/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.


Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

/*
Approach - apply sliding window, maintain a map for frequency at each instant calculate the no of replacement requried in substring (current window)
by using formual -> no of replacements = length of substring - max frequency of a character
if no of replacements are less than k then update the max length by considering the current window lengt
h else if no of replacements are greater than k then shrink the window from left and also decrement the frequency of left characters in map.
*/


int characterReplacement(string s, int k) {
    unordered_map<char,int> mp;
    int i=0,j=0;
    int maxFrequency = 0;
    int ans = 0;
    while(j < s.size()){
        mp[s[j]]++;
        maxFrequency = max(maxFrequency,mp[s[j]]);
        
        // no of replacements = length of substring - max frequency of a character
        int noOfReplacementRequired = (j-i+1) - maxFrequency;
        if(noOfReplacementRequired > k){
            mp[s[i]]--;
            i++;
        }
        else{
            ans = max(ans,j-i+1);
        }
        j++;
    }
    return ans;
}
