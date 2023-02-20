bool cmp(pair<int,string> a,pair<int,string> b){
    return a.first<b.first;
}
class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>>m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int ts) {
        m[key].push_back({ts,value});
    }
    
    string get(string key, int ts) {
        auto it=upper_bound(begin(m[key]),end(m[key]),pair<int,string>(ts,""),cmp);
        if(it==m[key].begin()) return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */