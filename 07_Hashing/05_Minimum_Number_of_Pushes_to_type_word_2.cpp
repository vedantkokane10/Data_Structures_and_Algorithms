/*
You are given a string word containing lowercase English letters.
Telephone keypads have keys mapped with distinct collections of lowercase English letters, 
which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"],
we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, 
but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.

Input: word = "aabbccddeeffgghhiiiiii"
Output: 24
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
"f" -> one push on key 7
"g" -> one push on key 8
"h" -> two pushes on key 9
"i" -> one push on key 9
Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
It can be shown that no other mapping can provide a lower cost.
*/

/*
Approach - Sort (Descending) the characters by their frequency since we have 8 keys (2-9) we map most frequent to unique 8 keys (1st occurence)
and then we can map the remaining characters at 2nd position since first occurence of first 8 keys are filled and  respectively also at 3rd , 4th.
 */


int minimumPushes(string word) {
    unordered_map<char,int> mp;
    for(auto x:word){
        mp[x]++;
    }
    vector<pair<int,char>> frequency;
    for(auto x:mp){
        frequency.push_back({x.second,x.first});
    }

    sort(frequency.begin(),frequency.end());
    reverse(frequency.begin(),frequency.end());
    int cnt = 0;
    int answer = 0;
    for(int i=0;i<frequency.size();i++){
        if(i % 8 == 0){
            cnt++;
        }
        cout<<frequency[i].second<<" "<<frequency[i].first<<endl;
        answer += (cnt * frequency[i].first);
    }

    return answer;

}
