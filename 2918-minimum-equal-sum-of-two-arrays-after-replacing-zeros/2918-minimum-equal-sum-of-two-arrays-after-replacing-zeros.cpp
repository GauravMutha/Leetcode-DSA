class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size(),n2=nums2.size(),zcount1=0,zcount2=0;
        long long sum1=0,sum2=0;
        
        for(int j=0,i=0;i<n1 || j<n2;){
            if(i<n1) sum1+=(long long)nums1[i],zcount1+=(nums1[i]==0) , i++;
            if(j<n2) sum2+=(long long)nums2[j],zcount2+=(nums2[j]==0), j++;
        }
        sum1+=zcount1, sum2+=zcount2;
        cout<<sum2<<" "<<zcount2;
        if((sum1<sum2 && zcount1==0) 
          ||(sum2<sum1 && zcount2==0)) return -1;
           
        return max(sum1,sum2);
    }
};