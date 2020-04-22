/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

/*
 Intuition:
 
1) If we sort all the strings which are anagrams, we will get a same sorted string.
2) We can sort a string using O(NlogN) time using inbuilt sort() function, but since we know that maximum unique characters
   in a string are '26', we can use COUNTING SORT which uses a frequncy count of a character and generates a sorted string.
3) Now we will map all the anagram strings to their sorted string and hence we will be able to group anagram's together.    

*/

class Solution {
public:
     
    string Sort(string s)  // This function is used to sort a given string using CNOUNTING SORT in O(N) time.
    {
        int counter[26] = {0}; // Hashmap of 26v characters to store frequency of each characters
        for (char c : s) 
        {
            counter[c - 'a']++; // Increment counter for each character
        }
        string t;
        for (int c = 0; c < 26; c++)  // This loop traverses from 'a' to 'z' and appends i'th character to a final string counter[i] times. 
        {
            t += string(counter[c], c + 'a');
        }
        return t; 
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
       unordered_map<string, vector<string>> mp; // This map has a key as a sorted array and its values are a set of anagrams.
        for (string s : strs)   // For each input, sort it and then add to its appropriate key's vector.
        {
            mp[Sort(s)].push_back(s); 
        }
        vector<vector<string>> ans;
        for (auto p : mp)  // This loop just converts given mapping into a required output format i.e 2-D matrix
        { 
            ans.push_back(p.second);
        }
        return ans;
    }
};

