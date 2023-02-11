//Looping solution was kind of linear search
//This is bineary search
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int start=1 , end=grades.size(),n=end,maxGroups=0;
        long totalGrades=0,mid=0;
        while(start<=end){
            mid= start + (end-start)/2;
            totalGrades=mid*(mid+1)/2;
            
            if(totalGrades<=n) maxGroups=(int)mid ,start=mid+1;
            else end=mid-1;
        }
        
        return (int)maxGroups;
    }
};