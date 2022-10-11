class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int len=votes[0].size();
        vector<vector<int>>rank(26,vector<int>(len+1,0));
        string res;
        /*this fills the  team name letter into the last position of vector
        thats why we have taken len +1 size of inner vectors*/
        for(auto c : votes[0])
            rank[c-'A'][len]=c;
        /*this is to fill votes value , every inner loop iteration is like
        addition of one vote to each team,by one member*/
        
        for(auto v : votes)
            for(int i=0;i<v.size();i++)
                rank[v[i]-'A'][i]--;
        sort(begin(rank),end(rank));
        
        for(int i=0;i<len;i++)
            res+=rank[i][len];
        
        return res;
    }
};

/*C++ sorting is always in ascending order therefore we have used a trick here.
We have minus the vote in second loop this way more negative value comes at
front and abs of that is desired highest vote*/