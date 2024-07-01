/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.
Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. 
Deadline of the job is the time before which job needs to be completed to earn the profit.

Example 1:
Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).

Example 2:
Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).
*/

/*
Approach - 
So we have deadline for each job that means we can complete the job earlier as well.
But we will assume that we complete most of the jobs at the deadline itself.
First sort the jobs based on profit in descending order then maintain a array of n+1 size for done tasks
traverse through the sorted array of jobs get the deadline check if it is not marked with any other job
if it is not marked then mark it and add the profit totalProfit and increment the totalJobs,
but if its marked then traverse backwards from current deadline in done array and find a empty position
if found then then mark it and add the profit totalProfit and increment the totalJobs else we can schedule the current job.
*/


const static bool cmp(Job &a, Job &b){
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
    int totalJobs = 0;
    int totalProfit = 0;
    
    
    sort(arr,arr+n,cmp);
    vector<int> done(n+1,-1);
    for(int i=0;i<n;i++){
        int currentDeadLine = arr[i].dead;
        int currentID = arr[i].id;
        int currentProfit = arr[i].profit;
        if(done[currentDeadLine] == -1){
            done[currentDeadLine] = currentID;
            totalJobs++;
            totalProfit += currentProfit;
        }
        else{
            while(currentDeadLine > 0 && done[currentDeadLine] != -1){
                currentDeadLine--;
            }
            if(currentDeadLine != 0){
                done[currentDeadLine] = currentID;
                totalJobs++;
                totalProfit += currentProfit;
            }
        }
    }
    
    
    
    return {totalJobs,totalProfit};
} 
