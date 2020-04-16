/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/


class Solution {
public:
    bool isHappy(int n)  // A function to return a boolean answer
    {
       unordered_map<int,int>mp; // A map to store the occurance of each number so as to detect a cycle
       int nnum=0; // A variable to store a sum of squares of a numbers.
       while(1)    // Iterating while loop which will run till we do not return any answer
       {               
            while(n)   // A loop to find a sum of squares of a number n 
            {
                int x=n%10;  // Find a digit present at a unit place of a number
                x*=x;        // Find its square
                nnum+=x;     // Add the square to sum of square of all the digits we have seen previously
                n/=10;       // Reduce the digit, by dividing it by 10
            }
            n=nnum;          // Copy a newly generated number to n
            
            if(nnum==1)      // Check if newly formed number is 1, if yes then return TRUE
            {
                   return 1;
            }
            else             // If newly formed number is not equal to 1 then check if we have seen that number before by doing a lookup in a map 
            {
                    if(mp[nnum]==1) // If we have seen that number before, then cycle exists and we cannot reach to 1 by any further calculations
                    {
                        return 0;
                    }    
                    else            // If we have not seen that number before then add it to the map
                    {
                        mp[nnum]=1;
                    }
            }
           nnum=0;              // Reset nnum to zero so as make it ready for a new iteration
        }
    }
};


/*
Instead of using while(1) in the above code, even if you iterate from 0 to 810 it should work because the maximum value of sum of squares
of each digit in a number will not be greater than 801, whyy???? 

beause Int has maximum 10 digits and it all those 10 digits are 9's i.e N=9999999999 then sum of squares is 10*81 = 810.

But to be more precise and to get a mpre tighter upper bound, if we draw a directed graph in which a vertices will be a numbers and edges between vertices 'v1' and 'v2' (where 1<=v1,v1<=810) represents that 
the sum of squares of digits on the number 'v1' is equal to number 'v2' then the maximum edges required to form a cycle are 18.

and if given number 'N' is greater than 810 then in one transition of sum of squares of digits, the number gets concerted between the range 1 to 810 and after that it will take
maximum 18 steps to form a cycle or to get coverted to '1'.

hence, maximum steps required are 19 hence our more efficient code looks like follows.

*/

class Solution {
public:
    bool isHappy(int n)  // A function to return a boolean answer
    {
       unordered_map<int,int>mp; // A map to store the occurance of each number so as to detect a cycle
       int nnum=0; // A variable to store a sum of squares of a numbers.
       for(int i=0;i<19;i++)    // Iterating for loop which will run till maximum 19 steps
       {               
            while(n)   // A loop to find a sum of squares of a number n 
            {
                int x=n%10;  // Find a digit present at a unit place of a number
                x*=x;        // Find its square
                nnum+=x;     // Add the square to sum of square of all the digits we have seen previously
                n/=10;       // Reduce the digit, by dividing it by 10
            }
            n=nnum;          // Copy a newly generated number to n
            
            if(nnum==1)      // Check if newly formed number is 1, if yes then return TRUE
            {
                   return 1;
            }
            else             // If newly formed number is not equal to 1 then check if we have seen that number before by doing a lookup in a map 
            {
                    if(mp[nnum]==1) // If we have seen that number before, then cycle exists and we cannot reach to 1 by any further calculations
                    {
                        return 0;
                    }    
                    else            // If we have not seen that number before then add it to the map
                    {
                        mp[nnum]=1;
                    }
            }
           nnum=0;              // Reset nnum to zero so as make it ready for a new iteration
        }
    }
};

