//3 pass solution
//Without making graph
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size(),curr=0,depth=0,maxDist,minOfmaxes=INT_MAX,res=-1;
        vector<int>dist1(n,INT_MAX),dist2(n,INT_MAX);
        
        curr=node1, depth=0;
        while(curr!=-1 && dist1[curr]==INT_MAX){
            dist1[curr]=depth;
            curr=edges[curr];
            depth++;
        }
        curr=node2, depth=0;
        while(curr!=-1 && dist2[curr]==INT_MAX){
            dist2[curr]=depth;
            curr=edges[curr];
            depth++;
        }
        
        for(int i=n-1;i>=0;i--){
            if(dist1[i]==INT_MAX || dist2[i]==INT_MAX) continue;
            maxDist=max(dist1[i],dist2[i]);
            if(minOfmaxes>=maxDist)
                minOfmaxes=maxDist , res=i;
        }
        
        return res;
    }
};