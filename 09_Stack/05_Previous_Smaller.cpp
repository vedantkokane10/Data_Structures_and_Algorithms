/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

For Example
Input 1:
    A = [4, 5, 2, 10, 8]
Output 1:
    G = [-1, 4, -1, 2, 2]
Explaination 1:
    index 1: No element less than 4 in left of 4, G[1] = -1
    index 2: A[1] is only element less than A[2], G[2] = A[1]
    index 3: No element less than 2 in left of 2, G[3] = -1
    index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
    index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]
    
Input 2:
    A = [3, 2, 1]
Output 2:
    [-1, -1, -1]
Explaination 2:
    index 1: No element less than 3 in left of 3, G[1] = -1
    index 2: No element less than 2 in left of 2, G[2] = -1
    index 3: No element less than 1 in left of 1, G[3] = -1
*/


/*
Same appraoch as previous but here we have only 1 array so directly asnwer can be stored no need of mapping.
Here we do change the comparision operator.
*/
vector<int> prevSmaller(vector<int> &A) {
    stack<int> s1;
    int n = A.size();
    vector<int> ans(n,-1);
    ans[0] = -1;
    s1.push(A[0]);
    for(int i=1;i<n;i++){
        if(A[i] > s1.top()){
            ans[i] = s1.top();
            s1.push(A[i]);
        }
        else{
            while(!s1.empty() && A[i] <= s1.top()){
                s1.pop();
            }
            
            if(s1.empty()){
                ans[i] = -1;
                
            }
            else{
                ans[i] = s1.top();
            }
            s1.push(A[i]);
        }
    }
    
    return ans;
}
