//sort + comparator
class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        bool aliceTurn=true;
        int aliceScore=0 , bobScore=0;
        vector<pair<int,int>>vec;
        
        for(int i=0;i<a.size();i++)
            vec.push_back({a[i]+b[i],i});
        sort(begin(vec),end(vec),[](auto  a,auto  b){
            return a.first>b.first;
        });
        
        for(int i=0;i<vec.size();i++){
            if(aliceTurn) aliceScore+=a[vec[i].second];
            else bobScore+=b[vec[i].second];
            
            aliceTurn=!(aliceTurn);
        }
        
        if(aliceScore>bobScore) return 1;
        else if(aliceScore<bobScore) return -1;
        
        return 0;
    }
};