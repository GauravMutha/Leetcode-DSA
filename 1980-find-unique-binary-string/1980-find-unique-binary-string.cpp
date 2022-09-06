class Solution {
public:
    string binstr(int num,int n){
        string res;
        while(num){
            res+=(num%2)?'1':'0';
            num/=2;
        }
        while(n-res.size())res+="0";
        reverse(res.begin(),res.end());
        return res;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size(),res=0;
        vector<int>vec;
        for(auto str : nums){
            vec.push_back(std::stoi(str,nullptr,2));
        }
        
        for(int i=0;i<pow(2,n);i++){
            auto it=std::find(vec.begin(),vec.end(),i);
            if(it==vec.end()){
                res=i;
                break;
            }
        }
            return binstr(res,n);
    }
};

//Logic---> Converting Every string of nums into numbers then checking 
//by generating all the binary numbers for n bits where n is size of nums.

//TC-->
//SC-->