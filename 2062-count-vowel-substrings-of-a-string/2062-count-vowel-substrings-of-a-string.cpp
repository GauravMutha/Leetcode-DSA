//SLIDING WINDOW - ATMOST TRICK
//TC--->O(N) SC---->O(1)
class Solution {
public:
    bool isvowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int atmost(string s , int k){
        int i=0,j=0,count=0;
        unordered_map<char,int>freq;
        
        while(j<s.size()){
            if(!isvowel(s[j])){
                freq.clear();
                j++;
                i=j;
                continue;
            }
            freq[s[j++]]++;
            while(freq.size()>k){
                freq[s[i]]--;
                if(freq[s[i]]==0) freq.erase(s[i]);
                i++;
            }
            count+=(j-i+1);
        }
        return count;
    }
    
    int countVowelSubstrings(string word) {
       return (atmost(word,5)-atmost(word,4));
    }
};