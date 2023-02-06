//priority queue max heap

typedef pair<double,pair<int,int>>p;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        double res=0;
        priority_queue<p> maxh;
        int pass=0,total=0;
        //putting potential growths in maxheaps with corresponding ratios
        for(int i=0;i<classes.size();i++){
            pass=classes[i][0];
            total=classes[i][1];
            
            long double growth=double(pass+1)/(total+1) - double(pass)/total;
            
            maxh.push({growth,{pass,total}});
        }
        
        //assigning extra students on basis of growth and updating the same
        while(extra--){
            pass=maxh.top().second.first;
            total=maxh.top().second.second;
            maxh.pop();
            
            pass++ , total++; //assigning extra students
            
            //updating growth to next potential growth of current ratio
            long double growth=double(pass+1)/(total+1) - double(pass)/total;
            maxh.push({growth,{pass,total}});
            
        }
        
        //calculating the average pass ratio
        while(!maxh.empty()){
            pass=maxh.top().second.first;
            total=maxh.top().second.second;
            maxh.pop();
            
            res+= double(pass)/total;
        }
        return double(res)/classes.size();
    }
};