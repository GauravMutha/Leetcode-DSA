class Solution {
public:
    bool isLongPressedName(string n, string t) {
        int i=0,j=0;
        char current;
        while(i<n.size() || j<t.size()){
            current =n[i];
            if(n[i]!=t[j]) return false;
            i++ ,j++;
            if(n[i]!=t[j])
                while(current==t[j])
                    j++;
        }
        return true;     
    }
};