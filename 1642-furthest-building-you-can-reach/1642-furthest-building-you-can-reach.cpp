//Priority Queue + min heap
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>minh;
        int jumpHeight=0,n=heights.size() , i=0;
        
        while(i<(n-1) && (size(minh) < ladders)){
            jumpHeight=heights[i+1]-heights[i];
            if(jumpHeight>0)
                minh.push(jumpHeight);
            i++;
        }
        
        while(i<(n-1)){
            jumpHeight=heights[i+1]-heights[i];
            if(jumpHeight<=0) {i++ ; continue;}
            if(!minh.empty() && (jumpHeight > minh.top())){
                bricks-=minh.top();
                minh.pop();
                minh.push(jumpHeight);
            }
            else bricks-=jumpHeight;
            if(bricks<0) return i;
            i++;
        }
        
        return i;
    }
};