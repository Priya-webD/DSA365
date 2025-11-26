/*
Problem: Count Occurences of Anagrams
Apprach: Sliding window + HashMap(Frequency Map)
Difficulty: Medium 

Brute Force Apprach: 
Pseudocode:

count = 0
sortPat = sort(pat)

for i from 0 to n-k:
    sub = txt[i to i+k-1]
    if sort(sub) == sortPat:
        count++

return count

Brute Force Time Complexity: O((n-k+1) * k log k)
Brute Force Space Complexity: O(k)
*/

//Optimized Approach: 
// Time Complexity: O(n)
// Space Complexity: O(1) or O(k) depending on alphabet size

// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        //step 1 to create a mppat map
    map<char,int> mppat;
    for(int idx=0; idx<pat.size(); idx++){
        char c = pat[idx];
        mppat[c] = mppat[c] + 1;
        // f = f:0 +1 = 1
      }
      int i=0;
      int j=0;
      int k = pat.size();
      int n = txt.size();
      int ans =0; //keep the track of the number of anagrams
      
      map<char, int> mpwindow; //map for surrent element 
      
      while(j<n){
          //calculations
          //current char at j ko mpwindow me include kr do
          mpwindow[txt[j]]++;
          
          //window size < k
          if(j-i+1 < k){
              j++;
          }
          //window size == k
          else if(j-i+1 == k){
              //mppat == mpwindow then ans++
              if(mpwindow == mppat){ 
                  ans++;
              }
              //slide the window 
              //remove ith element from the window 
              mpwindow[txt[i]]--;
              //this will only reduce the frequency of the char
              //but not remove the char completely 
              //to do that => erase that i from the window => if it is 0
              if(mpwindow[txt[i]] == 0){
                  mpwindow.erase(txt[i]);
              }
              //i ko aage badha do
              //j ko aage badha do
               i++;
               j++;
          }
        }
        return ans;
    }
};
