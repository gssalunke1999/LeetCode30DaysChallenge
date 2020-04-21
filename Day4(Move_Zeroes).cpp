/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

/*
--------INTUITION--------
We will use two pointers method in which one pointer will be always be less than other and it will 
always point to an index which contains a '0', and other pointer will always point to non zero elemnts 
index.

At any point of time if above condition satisfies then we will swap the elements at both the positions.

If any of the pointer is violating above condition we should increment it.

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
      int slow=0,fast=1; // Intitialise two pointers
      while(fast<nums.size() && slow<nums.size()) // Loop till both pointers are less than array size
      {
          if(nums[fast]!=0 && nums[slow]==0) // Since fast will always be greater than slow, if fast contains a non zero element and slow is zero then swap them
          {
              int temp=nums[slow];
              nums[slow]=nums[fast]; // This is for swap
              nums[fast]=temp;
          }
          if(nums[fast]==0)  // If fast contains zero then increment it. 
          {
              fast++;
          }
          
          if(nums[slow]!=0)  // If slow is non zero then increment it
          {
              slow++;
          }
          
          if(slow>=fast)  // If at any point fast becomes less than or equal to slow then make fast = slow + 1
          {
              fast=slow+1;
          }
      }
    }
};