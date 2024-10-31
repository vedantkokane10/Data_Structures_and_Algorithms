/*
1423. Maximum Points You Can Obtain from Cards

There are several cards arranged in a row, and each card has an associated number of points.
The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Example 2:
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Example 3:
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.


Approach - 
We can either pick first k elements or last k  elements or some elements from starting and ending making the length k.

[1,2,3,4,5,6,1] , k = 3

we can pick [1,2,3] from start => sum = 6
we can pick [1,2,1] (1,2) from start and 1 from end => sum = 4
we can pick [1,1,6] 1 from start and (1,6) from end => sum = 8
we can pick [1,6,5] from end  => sum = 12

max sum is 12 which is given by [1,6,5]

Approach - 
First calculate sum from starting upto k elements.
Then delete one by one single element from end of left side and add one by one element from right end of array
compare and store the max element.
*/


int maxScore(vector<int>& cardPoints, int k) {
    int leftSum = 0;
    for(int i=0;i<k;i++){
        leftSum += cardPoints[i];
    }
    int maxSum = leftSum;
    int j = 1;
    int rightSum = 0;
    int n = cardPoints.size();
    for(int i=k-1;i>=0;i--){
        rightSum += cardPoints[n-j];
        cout<<cardPoints[n-j]<<" ";
        leftSum = leftSum - cardPoints[i];
        int currentSum = leftSum  + rightSum;
        maxSum = max(maxSum,currentSum);
        j++;
    }

    return maxSum;
}
