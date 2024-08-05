/*
Source - GFG

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], 
where arr[i]  is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :
You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. 
The picked fruits must fit in one of the baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array of fruits, return the maximum number of fruits you can pick.

Examples:
Input: arr[]= [2, 1, 2]
Output: 3
Explanation: We can pick one fruit from all three trees. Please note that the type of fruits is same in the 1st and 3rd baskets.

Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: It's optimal to pick from the last 5 trees. Please note that we do not pick the first basket as we would have to stop at thrid tree which would result in only 2 fruits collected.

*/

/*
Approacg - Traditional Sliding window with k = 2, here I used map approach but it will take constant space because map cannot have size greater than 2.

TC - O(N)
SC - O(1)
*/

int totalFruits(vector<int> &arr) {
    int j = 0;
    int i = 0;
    int mx = 0;
    int sum = 0;
    unordered_map<int,int> mp;
    while(j < arr.size()){
        sum += arr[j];
        mp[arr[j]]++;
        while(mp.size() > 2){
            sum -= arr[i];
            mp[arr[i]]--;
            if(mp[arr[i]] == 0){
                mp.erase(arr[i]);
            }
            i++;
        }
        mx = max(mx,j-i+1);
        j++;
    }
    return mx;
}
