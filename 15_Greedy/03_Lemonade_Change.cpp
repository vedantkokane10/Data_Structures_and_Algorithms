/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills).
Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, 
return true if you can provide every customer with the correct change, or false otherwise.


Example 1:
Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Example 2:
Input: bills = [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.

*/

/*
Approach -
Each lemonade costs 5 so when bill is 5 its fine but if 
bill is 10 then need to have change of 5 and similarly when bill 20 we need to have change of 15 which can be either 3 coins of 5 or 1 coin 10 and 1 coin of 5 as change.

So  do maintain  counters of 5 and 10, and incrment 5  when diff is 0 and incrment 10  when diff is 5, similarly if 20 then prerform the above operation. 
*/


bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten = 0;
    for(auto x:bills){
        int diff = x - 5;
        if(diff == 0){
            five++;
        }
        else if(diff == 5){
            ten++;
            if(five > 0){
                five--;
            }
            else{
                return false;
            }
        }
        else if(diff == 15){
            if(five > 0 && ten > 0){
                five--;
                ten--;
            }
            else if(five >= 3){
                five = five - 3;
            }
            else{
                return 0;
            }
        }
    }

    return true;
}
