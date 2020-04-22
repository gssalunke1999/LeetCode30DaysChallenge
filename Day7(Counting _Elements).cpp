/*
Given an integer array arr, count element x such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.

 

Example 1:

Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
Example 2:

Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
Example 3:

Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
Example 4:

Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.
 

Constraints:

1 <= arr.length <= 1000
0 <= arr[i] <= 1000

*/


/*
Intuition:
1) Brute Force : For each element traverse an array and check if its next is present or not. (Beware of duplicate values) O(N^2)

2) Sorting : Sort a given array and if a last occurance of given element has next element occuring at next position then increment an anser count. (Beware of duplicate values) O(NlogN)

3) Using SET : Since SET precisely handles duplicate elements, insert all the elements in a set and again check if a next element is present in given set or not or not. 
  (Since SET uses self balancing tree in an internal implementation which requires O(logN) time to find an element, we can instead use UNORDERED MAP which takes O(1) time for finding an element)  

4) Using UNORDERED MAP : Insert an element in a map as a key and set its value to '1'. In second iteration check if a map contains its next number or not.
*/

class Solution {
public:
    int countElements(vector<int>& arr) 
    {
       unordered_map<int, int>mp; // Map to store a presence of a element
      
       int ans=0;
        
       for(int i=0;i<arr.size();i++)
       {
           mp[arr[i]]=1; // Set value of a key to 1 if an element is present in an array
       }
        
       for(int i=0;i<arr.size();i++)
       {
           if(mp[arr[i] + 1] == 1)  // Iterate over an array and check if next elemnt is present in a map or not
           {
               ans+=1;    // If element is present then increase a answer count.
           }
       }
        
       return ans; 
    }
};