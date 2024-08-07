/*
You are given an array people where people[i] is the weight of the ith person, 
and an infinite number of boats where each boat can carry a maximum weight of limit.
Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
Return the minimum number of boats to carry every given person.


Example 1:
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Example 2:
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Example 3:
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
*/

// Approach - Sort the array and apply traditional 2 pointers approach, but set the termination case when s and e crosses each other
// end pointer will always decrease, because the weight pointed by end pointer can be greater than limit (sorted)

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(),people.end());
    int s = 0, e = people.size() - 1;
    int cnt = 0;
    while(s <= e){
        if(people[s] + people[e] <= limit){
            s++;
            e--;
        }
        else{
            e--;
            // when s == e then else block will be executed if people[s] + people[e] > limit
        }
        cnt++;
    }
    return cnt;
}
