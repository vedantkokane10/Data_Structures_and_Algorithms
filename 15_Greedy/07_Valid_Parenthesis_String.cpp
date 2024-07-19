/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

*/

bool checkValidString(string s) {
    // we will assum a range [0,infinity] where first element is min and second max
    // if s[i] -> ( then min , max will be incremented 
    // if s[i] -> ) then min , max will be decremented 
    // if s[i] -> * we have 3 choices add -1 or 0 or +1, so for min we will add -1 and for max we will add +1
    // if minimum range < 0 then we set it 0
    // at end return if minimum is 0 or not (true/false)
    int mn = 0;
    int mx = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            mn++;
            mx++;
        }
        else if(s[i] == ')'){
            mn--;
            mx--;
        }
        else{
            mn--;
            mx++;
        }
        if(mn < 0){
            mn = 0;
        }
        if(mx < 0){
            return 0;
        }
    } 
    return mn == 0;
}
