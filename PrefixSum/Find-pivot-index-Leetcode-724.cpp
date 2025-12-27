// Approach: Prefix and Suffix Sum
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        int totalSum = 0;

        // Calculate total sum of the array
        for(int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }

        int cumulativeSum = 0; // Prefix sum (left sum)

        // Traverse array to find pivot index
        for(int i = 0; i < nums.size(); i++)
        {
            int leftSum = cumulativeSum;
            int rightSum = totalSum - cumulativeSum - nums[i];

            // If left sum equals right sum, return index
            if(leftSum == rightSum)
            {
                return i;
            }

            // Update prefix sum
            cumulativeSum += nums[i];
        }

        // No pivot index found
        return -1;
    }
};
