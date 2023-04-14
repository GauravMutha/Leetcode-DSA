class Solution {
public:
    int partitionString(string s) {
        int l=0 ,r=0,n=s.size(),count=1;
        vector<bool>hash(127,false);

        while(r<n){
            if(hash[s[r]]==true){
                while(l!=r) hash[s[l]]=false , l++;
                count++;
            }
            hash[s[r]]=true;
            r++;
        }

        return count;
    }
};