typedef long long ll;
class Solution {
public:
    int check(int x,vector<int>&comp,vector<int>& stock, vector<int>& cost,int budget){
        ll spend=0;
        
        for(int i=0;i<comp.size();i++){
            spend+=max(1ll*x*comp[i]-stock[i],0ll)*cost[i];
        }
        
        return spend<=budget;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        ll ans=0;
        for(auto comp : composition){
            ll res=0 , l=0,h=1e9;
            
            while(l<=h){
                int mid= (l+h)/2;
                
                if(check(mid,comp,stock,cost,budget)){
                    res=mid;
                    l=mid+1;
                }
                else h=mid-1;
                
            }
            ans=max(ans,res);
        }
        return ans;
    }
};