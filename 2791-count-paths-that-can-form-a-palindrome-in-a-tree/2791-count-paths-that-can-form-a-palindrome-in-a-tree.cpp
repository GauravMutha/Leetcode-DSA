//Bit masking
class Solution {
public:
    unordered_map<int,int>masksFreq;
    vector<int>nodeMasks;
    vector<vector<pair<int,char>>>graph;
    
    void dfs(int currNode , int mask){
        masksFreq[mask]++;
        nodeMasks[currNode]=mask;
        
        for(auto p : graph[currNode]){
            int adjNode=p.first;
            int letter=p.second-'a';
            
            dfs(adjNode,mask^(1<<letter));
        }
        return;
    }
    
    long long countPalindromePaths(vector<int>& parent, string s) {
        
        int n=s.size();  //number of edges+1 =nodes) , for a tree
        
        graph.resize(n);
        nodeMasks.resize(n);
        
        //making graph parent->child , i.e. u->v
        for(int i=1;i<parent.size();i++){
            int u=parent[i];
            int v=i;
            graph[u].push_back({v,s[i]});
        }
        
        /*populating mp and nodeMasks
        this is to get the frequency of
        all masks.And,all nodes's
        masks*/
        dfs(0,0);
        
        long long ans=0;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<26;j++){
                int mask=nodeMasks[i]^(1<<j);
                ans+=masksFreq[mask]; //one character differing masks
            }
            ans+=masksFreq[nodeMasks[i]]-1;
        }
        
        return ans/2;
    }
};