class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zPickers=0,onePickers=0 , n=sandwiches.size();
        
        for(int i=0;i<n;i++){
            if(students[i]==1) onePickers++;
            else zPickers++;
        }
        
        for(int i=0;i<n;i++){
            
            if(sandwiches[i]==0 && zPickers==0) 
                return (n-i);
            else if(sandwiches[i]==1 && onePickers==0) 
                return (n-i);
            
            if(sandwiches[i]==0) zPickers--;
            else onePickers--;
        }
        
        return 0;
    }
};