//Djisktra
typedef pair<int,pair<int,int>> pip;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int dir[5]={0,-1,0,1,0};
        
        while(pq.size()){
            
            auto p=pq.top();
            pq.pop();
            
            int diff=p.first;
            int row=p.second.first;
            int col=p.second.second;
            
            if(row==m-1 && col==n-1) return diff;
            
            for(int k=0;k<=3;k++){
                int newr=row+dir[k] , newc=col+dir[k+1];
                if(newr<0 || newc<0 || newr>=m || newc>=n) continue;
                int newEffort=max(abs(heights[newr][newc]-heights[row][col]),diff);
                if(newEffort<dist[newr][newc]) dist[newr][newc]=newEffort, pq.push({newEffort,{newr,newc}});
            }
        }
        
        return 0;
    }
};