/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
class MiniTwitter {
    static int serial;
    struct TimedTweet{
        Tweet t;
        int serial;
        TimedTweet(Tweet & t, int s) : t(t), serial(s){
        }
    };
    unordered_map<int, vector<TimedTweet>> hash;
    unordered_map<int, set<int>> follower;
    vector<TimedTweet> getRecent10TimedTweet(int id){
        if(hash.find(id) == hash.end()){
            return {};
        }
        vector<TimedTweet> result;
        int cnt = 0;
        for(auto riter = hash[id].rbegin(); cnt < 10 && riter!=hash[id].rend(); riter++, cnt++){
            result.push_back(*riter);
        }
        return result;
    }
    vector<Tweet> getTweets(vector<TimedTweet>& tt, int maxCnt){
        vector<Tweet> result;
        for(int i = 0; i < maxCnt && i < tt.size(); i++){
            result.push_back(tt[i].t);
        }
        return result;
    }
public:
    MiniTwitter() {
        // initialize your data structure here.
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        //  Write your code here
        Tweet t = Tweet::create(user_id, tweet_text);
        hash[user_id].push_back(TimedTweet(t, serial++));
        return t;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        vector<TimedTweet> tmp(getRecent10TimedTweet(user_id));
        for(auto f : follower[user_id]){
            auto ret = getRecent10TimedTweet(f);
            copy(ret.begin(), ret.end(), back_inserter(tmp));
        }
        sort(tmp.begin(), tmp.end(), [](const TimedTweet& t1, const TimedTweet& t2){return t1.serial > t2.serial;});
        vector<Tweet> result = getTweets(tmp, 10);
        return result;
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet>  getTimeline(int user_id) {
        // Write your code here
        auto ret = getRecent10TimedTweet(user_id);
        return getTweets(ret, 10);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        follower[from_user_id].insert(to_user_id);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        follower[from_user_id].erase(to_user_id);
    }
};
int MiniTwitter::serial = 0;