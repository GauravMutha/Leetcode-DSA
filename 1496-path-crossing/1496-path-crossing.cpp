class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>s;
        s.insert({0,0});
        int x=0,y=0;
        for(int i=0;i<path.size();i++){
            char c=path[i];
            if(c=='N') y++;
            else if(c=='S') y--;
            else if(c=='E') x++;
            else if(c=='W') x--;
            
            s.insert({x,y});
            if(s.size()!=(i+2)) return true;
        }
        return false;
    }
};