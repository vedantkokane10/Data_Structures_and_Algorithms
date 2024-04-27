/******************************************************************************
Geet tries to run away from her home yet again and this time she takes Aditya along with her. 
However, before they could leave the house, Roop, Geet’s sister catches them running away and alarms everyone in the house. 
Now, Geet and Aditya hide in the house itself temporarily.

Geet’s locality is represented by an M*M grid and each cell represents a house. 
Geet’s house is at the source cell. The cells of the grid may either be empty or occupied by some obstacle except if it is the source cell (initial cell).
An empty cell represents a house which is safe to hide in while the one with obstacle has guards. So, Geet definitely can’t hide in a house being guarded.
The columns of the grid are numbered 0 to M−1 from left and the rows are numbered 0 to M−1
from top. So, any cell present in ‘i′th row (from top) and ‘j′th column (from left) has the index (i−1, j−1).
You can perform the following operations at the same time in one step, if (A, B) is index of the present cell:
Move to cell (A−1, B) i.e., move one cell up
Move to cell (A, B+1) i.e., move one cell right
Move to cell (A+1, B) i.e., move one cell down
Move to cell (A, B−1) i.e., move one cell left
You are NOT allowed to move to a cell if it is occupied by an obstacle.
Once you move to a cell it is considered as covered. The source cell is considered as covered. 
You are required to help Geet and Aditya hide in maximum number of distinct houses possible. 
Formally, if the source cell has index (X, Y) and the grid contains K obstacles: (X1, Y1), (X2, Y2), … (Xk, Yk), 
find the maximum number of distinct cells which can be covered in N steps/operations.

Input Format - 
The first line of input contains an integer T, denoting the number of testcases. The description of the T
 testcases follow.
The first line of each testcase contains five integers- M, denoting the dimension of grid, N, the number of steps,
K, denoting the number of obstacles, and, X and Y, denoting the index (X, Y) of the source cell.
Then K lines follow, ‘i’th of which consists of two integers- Xi and Yi , the index of ‘i’th obstacle.

Output Format
For each testcase, print in a single line the maximum number of distinct cells which can be covered.

Constraints
1≤T≤100
1≤M≤103
0≤N≤103
0≤K<M2
0≤X,Y<M
0≤Xi,Yi<M

Testcase input -
2
3 2 2 1 1
0 2
1 0
4 0 3 0 1
0 3
1 3
2 3

Testcase output -
7
1

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,n,k,x,y;
        cin>>m>>n>>k>>x>>y;
        vector<vector<bool>> vis(m,vector<bool> (m,0));
        vis[x][y] = 1;
        for(int i=0;i<k;i++){
            int x1,y1;
            cin>>x1>>y1;
            vis[x1][y1] = 1;
        }
        
        queue<pair<int,int>> q1;
        q1.push({x,y});
        int cnt = 1;
        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};
        while(!q1.empty() && n > 0){
            int sz = q1.size(); 
            n--;
            for(int i=0;i<sz;i++){
                int row = q1.front().first;
                int col = q1.front().second;
                q1.pop();
                for(int i=0;i<4;i++){
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < m){
                        if(!vis[nrow][ncol]){
                            vis[nrow][ncol] = 1;
                            cnt++;
                            q1.push({nrow,ncol});
                        }
                    }
                }
            }
        }
        
        cout<<cnt<<endl;
        
    }
    

    return 0;
}
