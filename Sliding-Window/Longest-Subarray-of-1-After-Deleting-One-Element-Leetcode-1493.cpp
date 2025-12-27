//Approach : Sliding Window
//time complexity : O(n)
//space complexity : O(1)
class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxLen = 0;         //store maximum subarray length
        int left = 0;           //left pointer of window
        int right = 0;          //right pointer of window

        int countZero = 0;
        while(right < nums.size())
        {
            //if found 0
            if(nums[right] == 0)
            {
                countZero++;
            }
            
            //shrink window when countZero exceed 1
            while(countZero > 1)
            {
                if(nums[left] == 0)
                {
                    countZero--;
                }
                left++;
            }

            //update subarray length
            maxLen = max(maxLen, right - left + 1);

            //move right pointer of window
            right++;
        }
        
        //problem requires deleting one element, the final answer is window size minus one
        return maxLen - 1;
    }
};





//Approach : Nested Loop
//time complexity : O(n^2)
//space complexity : O(1)
class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxLen = 0;             //store maximum subarray length

        //Genrate all subarray using two pointer of loop
        for(int i = 0; i<nums.size(); i++)
        {
            //count zero in current window
            int countZero = 0;
            for(int j = i; j<nums.size(); j++)
            {
                if(nums[j] == 0)
                {
                    countZero++;
                }
                
                //if countZero is greater than 1, we need to delete only one
                if(countZero > 1)
                {
                    break;
                }

                maxLen = max(maxLen, j-i+1);
            }
        }

        //problem requires deleting one element, the final answer is window size minus one
        return maxLen - 1;
    }
};