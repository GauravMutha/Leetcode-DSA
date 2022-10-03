class Solution {
public:
    int countVowelSubstrings(string word) {
        int i=0,j=0,k=0,vow=0,res=0;
        unordered_map<char,int>m={{'a',0},{'e',0},{'i',0},{'o',0},{'u',0}};
        for(int i=0;i<word.size();i++){
            if(m.count(word[i])){
                m[word[i]]++;
                vow+= (m[word[i]]==1);
                
                while(vow==5){
                    m[word[k]]--;
                    vow-=(m[word[k]]==0);
                    k++;
                }
                res+=(k-j);
            }
            else{
                m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = vow = 0;
                j = k = i + 1;
            }
        }
        return res;
    }
};