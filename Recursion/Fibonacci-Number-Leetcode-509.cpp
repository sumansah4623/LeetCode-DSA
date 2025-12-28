//Approach : Recursive
//time complexity : O(n)
//space complexity : O(n)    due to recursive stack
class Solution 
{
public:
    int fib(int n) 
    {
        //base case
        if(n == 0 || n == 1)
        {
            return n;
        }

        //Recursive relation
        int ans = fib(n-1) + fib(n-2);

        return ans;

    }
};





//Approach : Iterative approach
//time complexity : O(n)
//space complexity : O(1)
class Solution 
{
public:
    int fib(int n) 
    {
        if(n == 0 || n == 1)
        {
            return n;
        }

        int prev1 = 0;
        int prev2 = 1;

        int curr = 0;
        for(int i = 2; i<=n; i++)
        {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return curr;
    }
};