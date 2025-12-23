//Approach 1: Using Sliding Window
//time complexity : O(n)
//space complexity : O(1)
class Solution 
{
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        //value for souble data type
        double maxAvg = -std::numeric_limits<double>::max();

        //left and right pointer for window
        int left = 0;
        int right = 0;
        double sum = 0;

        //window forming
        while(right < nums.size())
        {
            sum  = sum + nums[right];
            
            int len = right - left + 1;         //length of current window

            if(len == k)
            {
                double avg = sum / (double)k;
                maxAvg = max(maxAvg, avg);

                sum = sum - nums[left];
                left++;   
            }

            right++;        //increment right pointers
        }

        return maxAvg;
    }
};