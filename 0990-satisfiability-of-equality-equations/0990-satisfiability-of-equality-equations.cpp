//DSUF
bool comp(string &a , string& b){
    return a[1]>b[1];
}
class Solution {
public:
    //merge two nodes
    void merge(char xParent, char yParent,vector<char>& parent,vector<int>& rank){
        if(rank[xParent]<rank[yParent])
            parent[xParent]=yParent;
        else if(rank[yParent]<rank[xParent])
            parent[yParent]=xParent;
        else 
            parent[yParent]=xParent , rank[xParent]++;
    }
        //finding parent
    char findParent(char node,vector<char>& parent){
        if(parent[node]==node){
            return node;
        }
        //path compression optimisation before returning
        char temp=findParent(parent[node],parent);
        parent[node]=temp;
        return temp;
    }
    bool doUnion(string& str,vector<char>& parent,vector<int>& rank){
        char x=str[0] , y=str[3];
        char xParent=findParent(x,parent);
        char yParent=findParent(y,parent);
        
        //if parents are equal for x and y variables
        if(str[1]=='='){
            if(xParent!=yParent) 
                merge(xParent,yParent,parent,rank);
            return true;
        }
        //but if the symbol is != then,
        if(xParent==yParent) return false;
        
        return true; //when ! symbol but parents are different 
    }
    bool equationsPossible(vector<string>& eq) {
        vector<char>parent(128);
        vector<int>rank(128,0);
        sort(eq.begin(),eq.end(),comp);
        //initialising parent
        for(int i=97;i<=122;i++){
            parent[i]=i;
        }
        for(auto &str : eq){
            //following is to ensure that left variable are always 
            if(str[0]>str[3]) swap(str[0],str[3]);
            if(doUnion(str,parent,rank)==false) return false;
        }
        return true;
        
    }
};