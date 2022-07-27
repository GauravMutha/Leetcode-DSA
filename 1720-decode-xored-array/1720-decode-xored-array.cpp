class Solution {
public:
   void calc(vector<int>& v,int first,int ind,vector<int>& ans){
        if(ans.size()==(v.size()+1)){
            return;
        }
        else if(first==v[ind]){
            ans.push_back(0);
        }
        else if(first==0){
            ans.push_back(v[ind]);
        }
        else {
        int temp=first;
        for(int i=0;i<log2(v[ind])+1;){
            int num=1;
            num=num<<i;
            if(num & v[ind]){
               if(temp&num){
                   temp=temp&~(1<<i);
               }
                else{
                    temp=temp|num;
                }
            }
            i++;
        }
        ans.push_back(temp);
        }
        calc(v,ans[ind+1],ind+1,ans);
}

 vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        calc(encoded,first,0,ans);
        return ans;
    }

};