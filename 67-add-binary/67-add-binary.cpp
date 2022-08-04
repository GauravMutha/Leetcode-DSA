class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0,i=0,j=0; string ans={};
        for(i=a.length()-1,j=b.length()-1;(i>=0&&j>=0);i--,j--){
            int num1=0,num2=0,result=0;
            num1=a[i]-'0'; num2=b[j]-'0';
            result=num1+num2+carry;
            
            if(result<=1){
                ans+=to_string(result);
                carry=0;
            }
            else if(result==2){
                ans+="0";
                carry=1;
            }
            else if(result==3){
                ans+="1";
                carry=1;
            }
        }
       if(carry==0){
           for(;i>=0;i--){ans+=a[i];}
           for(;j>=0;j--){ans+=b[j];}
       }
       else if(carry==1){
           for(;i>=0;i--){
               int result=carry+(a[i]-'0');
               if(result<=1){
                   carry=0;
                   ans+=to_string(result);
               }
               else if(result==2){
                   carry=1;
                   ans+="0";
               }
           }
           for(;j>=0;j--){
               int result=carry+(b[j]-'0');
               if(result<=1){
                   carry=0;
                   ans+=to_string(result);
               }
               else if(result==2){
                   carry=1;
                   ans+="0";
               }
           }           
       }
        if(carry==1)ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};