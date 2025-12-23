//Approach 1 : Iterative Approach
//time complexity : O(n)
//time complexity : O(1)
// class Solution 
// {
//   public:
//     int factorial(int n) 
//     {
//         int product = 1;
//         for(int i = 1; i<=n; i++)
//         {
//             product = product * i;
//         }
        
//         return product;
//     }
// };



//Approach 1 : Iterative Approach
//time complexity : O(n)
//time complexity : O(1)
class Solution 
{
  public:
    int factorial(int n) 
    {
        //base case
        if(n == 0)
        {
            return 1;
        }
        
        
        //Recursive Function
        int smallProblem = factorial(n-1);     //break big into small 
        int bigProblem = n * smallProblem;
        
        return bigProblem;
    }
};