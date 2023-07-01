class Tweet{
    public :
    int time;
    int tweetId;
    int userId;
    Tweet(int t , int tid , int uid) {
        time = t;
        tweetId = tid;
        userId = uid;
    }
};
class Twitter {
public:
    int time = 0;
    unordered_map < int , vector < Tweet >> tweet;
    unordered_map < int , set < int >> following;



    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back(Tweet{ time , tweetId , userId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        following[userId].insert(userId);
        auto comp = [](pair<int, Tweet>& a, pair<int, Tweet>& b){ return a.second.time < b.second.time; };
        priority_queue<pair<int, Tweet>, vector<pair<int, Tweet>>, decltype(comp)> pq(comp);
        for(auto it : following[userId]){
            int index = tweet[it].size() - 1;
            if(index >= 0){
                pq.push({index, tweet[it].at(index)});
            }
        }
        vector < int > ans;
        while(!pq.empty() && ans.size() < 10){
            pair<int , Tweet> p = pq.top();
            pq.pop();
            int id = p.second.tweetId;
            ans.push_back(id);
            int userId = p.second.userId;
            int nextIndex = p.first - 1;
            if(nextIndex >= 0) pq.push({nextIndex  , tweet[userId].at(nextIndex)});
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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
