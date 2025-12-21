//Appproach : Two-pointer
//time complexity : O(N)
//space complexity : O(1)
class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int start = 0;            //starting pointer
        int end = n - 1;          //ending pointers
        int maxArea = 0;          //variable for storing max Area

        while(start < end)
        { 
            int width = end - start;                       //find width
            int hght = min(height[start], height[end]);    //find height of curr rec
            int area = hght * width;                       //find area of rec
            
            //update maxArea in every iteration
            maxArea = max(maxArea, area);

            //increase or decrease width of rectangle
            if(height[start] > height[end])
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        return maxArea;
        
    }
};
