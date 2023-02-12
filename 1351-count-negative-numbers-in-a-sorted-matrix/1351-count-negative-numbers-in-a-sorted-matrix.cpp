//Breakpoint  search
//from upper point to lower left
//O(m+n)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res=0 , m=grid.size() , n=grid[0].size(),r=0,c=n-1;
        while(r<m){
            
            while(c>=0 && grid[r][c]<0) 
                c--;
            
            res+=n-c-1;
            r++;
        }
        return res;
    }
};