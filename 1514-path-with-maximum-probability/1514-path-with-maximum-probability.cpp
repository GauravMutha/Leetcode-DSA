//Djikstra Algorithm - Slightly modified
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //p[i] is probability of path from source to ith node
        vector<double>probabilities(n,double(0.0));
        vector<bool>visited(n,false);
        vector<vector<pair<int,double>>>graph(n);
        priority_queue<pair<double,int>>pq; //max heap
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double w=succProb[i];
            
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        
        probabilities[start]=1.0;
        pq.push({probabilities[start],start});
        
        while(!pq.empty()){
            auto [p,curr]=pq.top();
            pq.pop();
            if(!visited[curr]){
                visited[curr]=true;
                for(auto &[adjNode,w]: graph[curr]){
                    if(double(w*p) > probabilities[adjNode]){
                        probabilities[adjNode]=w*p;
                        pq.push({w*p,adjNode});
                    }
                }
            }
        }
        return probabilities[end];
    }
};