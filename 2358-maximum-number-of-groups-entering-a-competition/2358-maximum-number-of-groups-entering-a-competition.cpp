//looping
//O(sqrt(N))
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int total=0 , groups=0 ,n=grades.size();
        while(total<=n){
            groups++;
            total+=groups;
        }
        
        return groups-1;
    }
};