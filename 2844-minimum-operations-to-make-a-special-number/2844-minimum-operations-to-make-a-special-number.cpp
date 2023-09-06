class Solution {
public:
    int minimumOperations(string num) {
        
        bool exist5=false, exist0=false;
        int sz=num.size();
        
        for(int i=sz-1;i>=0;i--){
            
            char d=num[i];
            
            if(d=='0'){
                if(exist0) return sz-i-2;
                exist0=true;
            }
            if(d=='5'){
                if(exist0) return sz-i-2;
                exist5=true;
            }
            if((d=='2' || d=='7') && exist5) return sz-i-2;
        }
        return sz-exist0;
    }
};