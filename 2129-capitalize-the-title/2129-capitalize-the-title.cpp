class Solution {
public:
    string capitalizeTitle(string title) {
        int l=0,r=0,n=title.size();
        while(r<=n){
            l=r;
            while(r<n && title[r]!=32)
                title[r]=tolower(title[r]) ,r++;
            if(r-l>2) 
                title[l]=toupper(title[l]);
            r++;
        }
        return title;
    }
        
};