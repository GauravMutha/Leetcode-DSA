//Naive , Brute force
class Solution {
private:
    vector<string>ans;
public:
    void helper(string & ds,vector<bool>& visited,int szLimit){
        if(ds.size()==szLimit){
            ans.push_back(ds);
            return;
        }
        for(int i=1;i<=9;i++){
            if(visited[i]) continue;
            ds.push_back(i+'0');
            visited[i]=true;
            helper(ds,visited,szLimit);
            ds.pop_back();
            visited[i]=false;
        }
    }
    string smallestNumber(string pattern) {
        int szLimit=pattern.size()+1;
        string ds;
        vector<bool>visited(10,false);
        helper(ds,visited,szLimit);
        for(auto & str : ans){
            int i=0;
            for(i=0;i<pattern.size();i++){
                if((pattern[i]=='I' && str[i+1]>str[i]) || (pattern[i]=='D' && str[i+1]<str[i]) )
                    continue;
                break;
            }
            if(i>=pattern.size()) return str;
        }
        
        return "";
    }
};