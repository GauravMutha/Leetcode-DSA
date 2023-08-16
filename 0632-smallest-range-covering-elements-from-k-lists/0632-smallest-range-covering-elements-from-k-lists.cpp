//Its like merge k sorted arrays
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<vector<int>>st; //--> {va;ue,row,column}
        vector<int>res(2,0);
        int k=nums.size(), lb=0,ub=0,range=INT_MAX;
        
        for(int i=0;i<k;i++) st.insert({nums[i][0],i,0});
        
        while(true){
            //get new range and update res
            int ld=(*st.begin())[0],lr=(*st.begin())[1],lc=(*st.begin())[2];
            int hd=(*st.rbegin())[0];
            st.erase(st.begin());
            
            if((hd-ld)<range) range=hd-ld, res={ld,hd};
            
            //check if proceeding further makes sense
            if((lc+1)>=nums[lr].size()) break;
            
            st.insert({nums[lr][lc+1],lr,lc+1});
            
        }
        return res;
    }
};