class Solution {
public:
    string capitalizeTitle(string title) {
        int l=0,r=0,n=title.size();
        while(r<=n){
            if((title[r]==' ') || (r==n)){
                if(r-l>2) title[l]=toupper(title[l]);
                r++;
                l=r;
            }
            else{
                title[r]=tolower(title[r]);
                r++;
            }
        }
        
        return title;
    }
};