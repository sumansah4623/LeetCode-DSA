//Approach 1 : Using Sliding window
//time complexity : O(n)
//space complexity : O(1)
class Solution 
{
public:
    //function for checking character vowel 
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }

        return false;
    }

    int maxVowels(string s, int k) 
    {
        int maxVol = 0;            //store max number of vowel in substring
        int left = 0;              //left pointer of window
        int right = 0;             //right pointer of window

        int count = 0;             //for counting vowel in current substring
        while(right < s.length())
        {
            //if char is vowel
            if(isVowel(s[right]))
            {
                count++;
            }
            
            //size of window match
            if(right - left + 1 == k)
            {
                maxVol = max(maxVol, count);          //update maxVol
                if(isVowel(s[left]))                  //if char at left pointer is vowel
                {
                    count--;                          //first decrement
                }

                left++;                               //then move left pointer
            }

            right++;                 //move right pointer  of window
        }

        return maxVol;
    }
};


// //Approach 1 : Using nested loop
// //time complexity : O(n^2)
// //space complexity : O(1)
// class Solution 
// {
// public:
//     int maxVowels(string s, int k) 
//     {
//         // Stores maximum number of vowels found
//         int maxVol = 0;


//         // Loop through all possible starting indices of substrings of length k
//         for(int i = 0; i<= s.length()-k; i++)
//         {
//             //Counts vowels in current substring
//             int count = 0;

//             //Check exactly k characters starting from index i
//             for(int j = i; j< i+k ; j++)
//             {
//                 //If the current character is a vowel, increment count
//                 if(s[j] == 'a' ||s[j] == 'e' ||s[j] == 'i' ||s[j] == 'o' ||s[j] == 'u')
//                 {
//                     count++;
//                 }
//             }
  
//             //Update maximum vowels found so far
//             maxVol = max(maxVol, count);
//         }

//         return maxVol;
          
//     }
// };
