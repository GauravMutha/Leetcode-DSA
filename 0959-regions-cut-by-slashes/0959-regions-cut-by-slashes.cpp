//Disjoint Sets + Union Find approach
class Solution {
private:
    vector<int>parent  ,rank;
    int regions=1; //one region is always there regardless
public:
    // intitalise parent and rank
    void initParentAndRank(int dots){
        for(int i=0;i<(dots*dots);i++){
            parent[i]=i;
        }
        for(int i=0;i<dots;i++){
            for(int j=0;j<dots;j++){
                if(i==0 || j==0 || i==dots-1 || j==dots-1){
                    int dotNumber=i*dots+j;
                    if(dotNumber!=0) doUnion(0,dotNumber);
                }
            }
        }
        return;
    }
    //finding parent
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        //path compression optimisation before returning
        int temp=findParent(parent[node]);
        parent[node]=temp;
        return temp;
    }
    void doUnion(int x,int y){
        int xParent=findParent(x);
        int yParent=findParent(y);
        
        //if parents are equal for x and y nodes
        if(xParent==yParent){
            regions++;
            return;
        }
        //Union by rank optimisation
        //if parents are not equal for x and y nodes
        if(rank[xParent]<rank[yParent])
            parent[xParent]=yParent;
        else if(rank[yParent]<rank[xParent])
            parent[yParent]=xParent;
        else 
            parent[yParent]=xParent , rank[xParent]++; //we can make any one of the node parent
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int dots=n+1;
        parent.resize(dots*dots);
        rank.resize(dots*dots, 0);
        initParentAndRank(dots);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //if its a slash it connects two dots , we union two dots , which is "connecting the dots"
                int dotNumber1,dotNumber2;
                if(grid[i][j]=='/'){
                    dotNumber1=i*dots+(j+1);
                    dotNumber2=(i+1)*dots+(j);
                    doUnion(dotNumber1,dotNumber2);
                }
                else if(grid[i][j]=='\\'){
                    dotNumber1=i*dots+j;
                    dotNumber2=(i+1)*dots+(j+1);
                    doUnion(dotNumber1,dotNumber2);
                }
            }
        }
        return regions;
    }
};