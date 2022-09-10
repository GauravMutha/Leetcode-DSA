class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> res;
        vector<int>freq(tiles.size(),0);
        perm(tiles,res,freq);
        
        return res.size();
    }
    
    void perm(string& tiles,unordered_set<string>& res,vector<int>& freq){
        static string ds;
        if(ds.size()){
            res.insert(ds);
        }
       
        for(int i=0;i<freq.size();i++){
            char prevchar;
            while(prevchar==tiles[i])continue;
            if(!freq[i]){
                ds+=(tiles[i]);
                freq[i]=1;
                
                perm(tiles,res,freq);
                
                if(ds.empty())prevchar=ds.back();
                ds.pop_back();
                freq[i]=0;
            }
        }
    }
};