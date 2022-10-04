class Solution {
public:
    bool isspecial(char c){
        string temp="!@#$%^&*()-+";
        if(temp.find(c)!=-1) return true;
        return false;
    }
    bool strongPasswordCheckerII(string password) {
       int num=0,n=password.size();
       if(n<8) return false;
       
       for(int i=0;i<n;i++){           
           if((i!=0) && (password[i]==password[i-1])) return false;
           
           if((password[i]>=65) && (password[i]<=90))
               num|=(1);
           else if((password[i]>=97) && (password[i]<=122))
               num|=(1<<1);
           else if(isdigit(password[i]))
               num|=(1<<2);
           else if(isspecial(password[i]))
               num|=(1<<3);
           
      }
        return (num==15);
    }
};