/*Binary search but we use lower_bound function instead of explicitly doing Binar search*/
class Solution {
public:
    int maxDistance(vector<int>& n1, vector<int>& n2) {
        int maxDist=0,sz1=n1.size(),sz2=n2.size(),res=0;
        
        for(int i=0;i<n1.size();i++){
            int it=lower_bound(rbegin(n2),rend(n2),n1[i])-n2.rbegin();
            int j=sz2-it-1;
            if(j>=i) maxDist=max(maxDist,j-i);
        }
        return maxDist;
    }
};