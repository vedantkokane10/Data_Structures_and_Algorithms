/*
Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack.
Return a double value representing the maximum value in knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here.
The details of structure/class is defined in the comments above the given function.

Examples :
Input: n = 3, w = 50, value[] = [60,100,120], weight[] = [10,20,30]
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30,
to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0
Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 

Input: n = 2, w = 50, value[] = [60,100], weight[] = [10,20]
Output: 160.000000
Explanation: Take both the items completely, without breaking.
Total maximum value of item we can have is 160.00 from the given capacity of sack.
*/

/*
Approach - 
First sort the array of items in descending order based on ratio of (value/weight), then maintain answer = 0.0
iterate through the sorted items if current iterated weight less than or equal to remaining weight then add it completely (by adding value to answer)
and subtract it from reamining weight, if current iterated weigh greater than remaining weight then add the fractional part of current iterated weight
equal to remaining weight and increment the answer by (value[i] * remainingWeight) / wwight[i]. At end return answer.
*/



const static bool cmp(pair<int,int> &a,pair<int,int> &b){
    double r1 = (double)a.second / a.first;
    double r2 = (double)b.second / b.first;
    return r1 > r2;
}
double fractionalKnapsack(int w, Item arr[], int n) {
    vector<pair<int,int>> items;
    for(int i=0;i<n;i++){
        Item x = arr[i];
        items.push_back({x.weight,x.value});
    }
    sort(items.begin(),items.end(),cmp);
    double ans = 0.0;
    for(auto x:items){
        if(w > 0){
            if(x.first <= w){
                ans += x.second;
                w = w - x.first;
            }
            else{
                double rem = (double)(x.second * w) / x.first ;
                ans += rem;
                w = 0;
            }
        }
    }
    return ans;
}
