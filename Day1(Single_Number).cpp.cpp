/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) // Function which will return a required number
    {
      int x=0;   // A variable declared to store a parity 
      for(int i=0;i<nums.size();i++)  // For loop for iterating over each element in an array
      {
          x^=nums[i];  
          /*
             A parity generator statement which makes use of the following xor property
             1 ) Xor of any element 'p' with itself is equal to 0.
                 Let p = 5;
                 Binary representation of 5 is 101 hence,
                 1 0 1  (p)
               ^ 1 0 1  (p)
                 _____
                 0 0 0
                 
                 hence for any set of duplicate elements in a given array this statement will cancel them with each other.

          */
      }
      return x;  // returns the answer
    }
};