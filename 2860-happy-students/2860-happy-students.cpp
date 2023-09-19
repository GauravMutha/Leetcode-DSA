class Solution {
public:
    int countWays(vector<int>& nums) {
        int n=nums.size(), count=0;
        vector<int>vecs(n,0),vecg(n,0),hash(n,0);
        
        //make hash
        for(int i=0;i<n;i++) hash[nums[i]]++;
        
        //make vecs,vecg
        for(int i=0,j=n-1;i<n && j>=0;i++,j--){
            if(j==n-1) vecg[j]=hash[j];
            else vecg[j]=vecg[j+1]+hash[j];
            
            if(i==0) vecs[i]=hash[i];
            else vecs[i]=vecs[i-1]+hash[i];
        }
        
        //right shift and left shift
        for(int i=0,j=n-1;i<n-1 && j>0;i++,j--) vecg[i]=vecg[i+1], vecs[j]=vecs[j-1];
        vecg[n-1]=vecs[0]=0;
        
        for(int i=1;i<n;i++) if((hash[i]==0) && (vecs[i]==i)) count++; 
        
        for(int i=0;i<n;i++) cout<<hash[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<vecs[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<vecg[i]<<" ";
        
        return count+(hash[0]==0) + 1;
    }
};