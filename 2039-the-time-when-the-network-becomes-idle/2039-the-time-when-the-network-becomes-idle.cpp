//Djikstra
//We can use analogy to a train with every coach having equal distance
typedef pair<int,int>pii;
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size(),res=0,time=-1;
        vector<vector<int>>graph(n);
        vector<int>distances(n,INT_MAX);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        distances[0]=0;
        pq.push({distances[0],0});
        
        while(!pq.empty()){
            auto [dist,curr]=pq.top();
            pq.pop();
            
            for(auto adjNode:graph[curr]){
                if((dist+1)<distances[adjNode]){
                    distances[adjNode]=dist+1;
                    pq.push({distances[adjNode],adjNode});
                }
            }
        }
        
        for(int i=1;i<n;i++){
            
            //leftMessage is messages left  when first have already been recieved
            //- 1 as we cannot not count the first message amongst a left messages
            //because it has been recieved already
            int leftMessages=ceil(2.0*distances[i]/patience[i])-1;
            
            /*lastPos is position of last message from sender node i.
            Note that all messages will always remain equidistant
            from each  other by patience[i] unit so the below
            gives us further and last spell of distance our
            last message need to travel to go oback to its
            sender node*/
            int lastPos=leftMessages*patience[i];
            
            int total=2*distances[i]+lastPos;
            
            res=max(res,total);
        }
        return res+1;
    }
};

/*Note that it is theoretically not possible for last node that
it is yet to be recieved by master when first message has 
already reached the sender*/