class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string str(nums.size(),' ');
        back(str,nums.size(),0,nums);
        return str;
    }
    
    bool back(string& str,int n,int ind,vector<string>& nums){

        if(ind>=n){
            if(std::find(nums.begin(),nums.end(),str)==nums.end()){
                return 0;
            }
            return 1;
        }
        int flag0=0,flag1=0;
        str[ind]='0';
        flag0=back(str,n,ind+1,nums);

        if(flag0==1){
            str[ind]='1';
            flag1=back(str,n,ind+1,nums);
        }
        
        return (flag0 & flag1);
    }
};