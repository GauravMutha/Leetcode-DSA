//Slight optimisation
class Solution {
private:
    string ans="";
public:
    void helper(string & ds,vector<bool>& visited,int szLimit,string& patt){
        if(ans.size()) return;
        if(ds.size()==szLimit){
            ans=ds;
            return;
        }
        for(char c='1';c<='9' && ans.size()==0;c++){
            if(visited[c]) continue;
            if(ds.size()>0 && ((patt[ds.size()-1]=='I' && c<ds.back()) || (patt[ds.size()-1]=='D' && c>ds.back())))
                break;
            ds.push_back(c);   
            visited[c]=true;
            helper(ds,visited,szLimit,patt);
            ds.pop_back();
            visited[c]=false;
        }
    }
    string smallestNumber(string patt) {
        int szLimit=patt.size()+1;
        string ds;
        vector<bool>visited(127,false);
        helper(ds,visited,szLimit,patt);

        return ans;
    }
};