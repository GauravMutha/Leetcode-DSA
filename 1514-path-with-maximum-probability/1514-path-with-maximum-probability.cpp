//Djikstra Algorithm - Slightly modified
//Using set for better performance
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //p[i] is probability of path from source to ith node
        vector<double>probabilities(n,double(0.0));
        vector<bool>visited(n,false);
        vector<vector<pair<int,double>>>graph(n);
        multiset<pair<double,int>>st;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double w=succProb[i];
            
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        
        probabilities[start]=1.0;
        st.insert({probabilities[start],start});
        
        while(!st.empty()){
            auto it=(st.rbegin());
            int curr=it->second;
            double p=it->first;
            st.erase(*it);
            if(visited[curr]==false){
                visited[curr]=true;
                for(auto &[adjNode,w]: graph[curr]){
                    if(w*p > probabilities[adjNode]){
                        if(probabilities[adjNode]!=0) 
                            st.erase({probabilities[adjNode],adjNode});
                        probabilities[adjNode]=w*p;
                        st.insert({w*p,adjNode});
                    }
                }
            }
        }
        return probabilities[end];
    }
};