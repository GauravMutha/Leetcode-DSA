//Priority_queue max heap
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>maxh;
        int height_difference=0,i=0;
        
        for(i=0;i<heights.size()-1;i++){
            height_difference=heights[i+1]-heights[i];
            
            if(height_difference<=0) continue;
            
            maxh.push(height_difference);
            bricks-=height_difference;
            
            if(bricks<0){
                bricks+=maxh.top();
                maxh.pop();
                ladders--;
            }
            if(ladders<0) break;
        }
        return i;
    }
};