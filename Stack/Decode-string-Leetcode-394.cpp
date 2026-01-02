// Approach: Using two stacks (count + string)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution 
{
public:
    string decodeString(string s) 
    {
        stack<int> count;        // store numbers
        stack<string> str;       // store previous strings
        
        string curr = "";        // current decoded string
        int num = 0;             // current number
        
        for(char ch : s)
        {
            // If digit, build the number
            if(isdigit(ch))
            {
                num = num * 10 + (ch - '0');
            }
            // If '[', save state
            else if(ch == '[')
            {
                count.push(num);
                str.push(curr);
                num = 0;
                curr = "";
            }
            // If ']', decode substring
            else if(ch == ']')
            {
                int times = count.top(); count.pop();
                string prev = str.top(); str.pop();
                
                while(times > 0)
                {
                    prev += curr;
                    times--;
                }
                curr = prev;
            }
            // If alphabet, add to current string
            else
            {
                curr += ch;
            }
        }
        
        return curr;
    }
};
