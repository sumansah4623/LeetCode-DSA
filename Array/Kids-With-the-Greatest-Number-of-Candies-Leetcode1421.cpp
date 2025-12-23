//Approach : finding maxValue from array and then compare 
//time complexity : O(n)
//space complexity : O(1)
class Solution 
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        //size of given array
        int n = candies.size();

        //take vector for returing answer
        vector<bool> ans(n, false);

        //find maximum value of array
        int maxValue = 0;
        for(int i = 0; i<n; i++)
        {
            maxValue = max(maxValue, candies[i]);
        }

        //now comparing with maxVlue and candies with addind extra candies 
        for(int i = 0; i<n; i++)
        {
            if(candies[i] + extraCandies >= maxValue)
            {
                ans[i] = true;
            }
        }

        return ans;
    }
};