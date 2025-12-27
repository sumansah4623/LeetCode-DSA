//Approach : Sliding-Window
//time complexity : O(N)
//space complexity : O(1)
class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int maxLen = INT_MIN;            //variable for storing maximum con 1
        int left = 0;                    //left pointer
        int right = 0;                   //right pointer
  
        int countZero = 0;                 //count Zero in current window
        while(right < nums.size())
        {
            if(nums[right] == 0)
            {
                countZero++;                //if 0 then increment countOne
            }
            
            //shrink window when exceed k
            while(countZero > k)
            {
                if(nums[left] == 0)
                {
                    countZero--;
                }

                left++;
            }
            
            //update window size
            maxLen = max(maxLen, right - left + 1);

            //move right pointer in every iteration
            right++;
        }

        return maxLen;

    }
};







//Approach : nested loop for genrating all subarray
//time complexity : O(n^^2)
//space complexity : O(1)
class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int maxLen = 0;            //variable for storing maximum con 1
        

        for(int i = 0; i<nums.size(); i++)
        {
            //count Zero in current subarray
            int countZero = 0;       
            for(int j = i; j<nums.size(); j++)
            {
                if(nums[j] == 0)
                {
                    countZero++;
                }

                if(countZero > k)
                {
                    break;
                }

                maxLen = max(maxLen, j-i+1);
            }
        }

        return maxLen;

    }
};