class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int count=0;
        if((sx==fx) && (sy==fy)) return t!=1;
        int dx=abs(fx-sx), dy=abs(fy-sy);
        
        if(dy<=dx){
            count=dy;
            sx=(fx>sx) ? sx+count : sx-count;
            count+=abs(fx-sx);
        }
        else{
            count=dx;
            sy=(fy>sy) ? sy+count : sy-count;
            count+=abs(fy-sy);
        }
        
        return t>=count;
    }
};