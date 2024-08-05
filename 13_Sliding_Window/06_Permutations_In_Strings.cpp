/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2


Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").


Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

*/

/*
Approach - Maintain 2 Maps, 1 for string s1 and other that dynamically change while applying sliding winow, k = s1.size
Apply sliding window of k size iterate over 2 maps if each element is equal then return true else shrink window from left and 
also delete the the characters from second map.
*/

// TC - O(26 * N) ~ O(N)
// N = s2.size

bool checkInclusion(string s1, string s2) {
    unordered_map<char,int> mp1;
    for(auto x:s1){
        mp1[x]++;
    }
    unordered_map<char,int> mp2;
    int k = s1.size();
    int j=0,i=0;
    while(j < s2.size()){
        mp2[s2[j]]++;
        if(j-i+1 == k){
            bool f = 1;
            for(auto x:s1){
                if(mp1[x] != mp2[x]){
                    f = 0;
                    break;
                }
            }
            if(f == 1){
                return 1;
            }
            mp2[s2[i++]]--;
        }
        j++;
    }
    return 0;
}
