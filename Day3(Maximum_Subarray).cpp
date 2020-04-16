/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums)  // Function which will return a maximum sum 
    {
      int max_sum=INT_MIN;  // A variable initialised to minimum value of integer
      int sum_till=0;       // A variable which is used to store local sum while traversing
        
      int flag=0;      // flag is used to check if their is at least 1 non -ve present in a array 
      int max=INT_MIN;  // If flag remains 0 then we have to return a maximum element from all the given numbers 
      
      
      for(int i=0;i<nums.size();i++) // Iterate over an array
      {
          if(nums[i]>=0)   // If their is at least one non -ve number then make flag =1 and break the loop
          {
              flag=1;
              sum_till=0;
              break;
          }
          else // else find maximum element in an array
          {
              if(max<nums[i])
              {
                  max=nums[i];
              }
          }
      }
        
      if(flag==0) 
      {
          return max; // if no non -ve element is present then return the maximum element
      }
       
       
        // Code till now was just to handle corner cases
        
        // Following code uses Kadane's algorithm
        
      for(int i=0;i<nums.size();i++)
      {
         sum_till+=nums[i]; // Add current element to sum till now
         if(sum_till<0)     // If sum_till is less than zero then we should make sum_till = 0 becuase their is no point in returning a negative value
         {
             sum_till=0;
         }
         else // If local sum becomes greater than global sum then copy a local sum in global sum
         {
             if(sum_till>max_sum)
             {
                 max_sum=sum_till;
             }
         }
      }
        
      return max_sum;  // Return the global sum
    }
};

/*
This problem can also be solved using Divide and Conquer technique in O(nlogn) time.

Time complexity associated with various approaches is as follows
1) O(n^3) - Using 2 FOR loops to get each pair of 'i' and 'j' and another FOR loop for calculating the sum between them.
2) O(n^2) - By preprocessing the input array and converting it into a prefix sum array and further we can solve it using 2 FOR loops.
3) O(nlogn) - By using Divide and Conquer.
4) O(n) - Using Kadane's algorithm
*/