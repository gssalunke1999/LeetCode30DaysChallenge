/*
Best Time to Buy and Sell Stock II
Solution
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4

*/



/*
--------INTUITIONS--------
Bruteforce solution is to find all the possible transactions and then find the maximum profit yielding set. O(N^N).

Another solution is to subtract the previous minimum element from a current element, if current element is greater than its next element O(n).

*/

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
      if(prices.size()==0 || prices.size()==1) // Since at least 2 elements are required to have a non zero answer, if array length is less than 2 we return 0.
      {
          return 0;
      }
      int ans=0;  
      int prev_min=prices[0]; // This variable is used to store a minimum answer till now 
      for(int i=0;i<prices.size()-1;i++)
      {
          if(prices[i] > prices[i+1]) // If next elements is less than a current element then take a difference between current element and minimum element till now
          {
              ans+=(prices[i] - prev_min); // Add this difference in a final answer.
              prev_min=prices[i+1]; // Since prev_min is used now we have to update it, hence we assign it to next element
          }
      }
        
      if(prices[prices.size()-1] >= prices[prices.size()-2]) // Used to handle a corner case, if an array is sorted in non descending way.
      {
          ans+=(prices[prices.size()-1] - prev_min);
      }
        
      return ans;  
    }
};