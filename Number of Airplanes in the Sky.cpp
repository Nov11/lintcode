/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        if(airplanes.empty()){return 0;}
        
        vector<int> s;
        vector<int> e;
        for(auto item : airplanes){
            s.push_back(item.start);
            e.push_back(item.end);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        int result = 0;
        int acc= 0;
        for(int i = 0, j = 0; i < s.size() && j < e.size();){
            if(s[i] < e[j]){
                acc++;
                result=max(result, acc);
                i++;
            }else if(s[i] == e[j]){
                i++;
                j++;
            }else{
                acc--;
                j++;
            }
        }
        return result;
        // this is not correct
        // sort(airplanes.begin(), airplanes.end(), [](const Interval& i1, const Interval& i2){
        //     if(i1.end == i2.end){
        //         return i1.start < i2.start;
        //     }
        //     return i1.end < i2.end;
        // });
        
        // int result = 1;

        // for(int i = 1, j = 0; i < airplanes.size(); ){
        //     Interval& cur = airplanes[i];
        //     if(cur.start >= airplanes[j].end){
        //         j++;
        //     }else{
        //         i++;
        //         result = max(result, i - j);
        //     }
        // }
        
        // return result;
    }
};