//priority queue min heap
//We take top 10 most recent tweets by making a min heap
typedef pair<int,int>p;
class Twitter {
private :
    int ts;
    unordered_map<int,set<int>>followings;
    unordered_map<int,vector<p>>tweetDB; //tweet DataBase
public:
    Twitter() {
        ts=0;
        followings.clear();
        tweetDB.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        tweetDB[userId].push_back({ts++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<p,vector<p>,greater<p>>minh;
        int cnt=10,i=0;
        //go through users tweets
        auto userTs=tweetDB[userId]; //userTs ~ userTweets 
        for(auto it=userTs.rbegin();it!=userTs.rend()&&cnt>0;it++,cnt--){
            minh.push(*it);
            if(minh.size()>10) minh.pop();
        }
        //tweets of all the followings of this user;
        cnt=10;
        auto followSet=followings[userId];
        for(auto it1=followSet.begin();it1!=followSet.end();it1++){
            auto userTs=tweetDB[*it1];
            for(auto it2=userTs.rbegin();it2!=userTs.rend()&&cnt>0;it2++,cnt--){
                minh.push(*it2);
                if(minh.size()>10) minh.pop();
            }
        }
        
        //now finally getting top 10 entries of max heap into res
        vector<int>res(minh.size(),0);
        i=res.size()-1;
        while(!minh.empty() && i>=0){
            res[i--]=minh.top().second;
            minh.pop();
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */