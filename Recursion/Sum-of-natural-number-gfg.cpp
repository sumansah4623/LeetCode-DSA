//Approach 1 : iterative approach
//time complexity : O(n)
//space complexity : O(1)
class Solution 
{
  public:
    int findSum(int n) 
    {
        int sum = 0;
        for(int i = 1; i<=n; i++)
        {
            sum = sum + i;
        }
        
        return sum;
    }
};




// Approach 2 : Recursive approach
// Time Complexity : O(n)
// Space Complexity : O(n)     due to recursive call stack
class Solution 
{
  public:
    int findSum(int n) 
    {
        //base case
        if(n == 1)
        {
            return 1;
        }
        
        //Recursive Function
        int smallProblem = findSum(n-1);
        int bigProblem = n + smallProblem;
        
        return bigProblem;    //return solution of big problem
    }
};
