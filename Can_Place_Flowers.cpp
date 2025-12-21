//Approach : Greedy approach
//time complexity : O(n)
//space complexity : O(1) 
class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int len = flowerbed.size();

        for(int i = 0; i < len; i++)
        {
            //If i == 0, there is no left neighbor → safe
            bool leftbed  = (i == 0 || flowerbed[i-1] == 0);
            bool rightbed = (i == len - 1 || flowerbed[i+1] == 0);

            if(flowerbed[i] == 0 && leftbed && rightbed)
            {
                flowerbed[i] = 1;   //place flower
                n--;                //decrement flower No
            }
        }
        return n <= 0;   //At the end, check if all n flowers are placed
    }
};
