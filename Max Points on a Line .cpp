/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    double slope(Point& p1, Point& p2){
        return double(p1.y - p2.y) / (p1.x - p2.x);
    }
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        if(points.size() == 1){return 1;}
        
        int result = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<double, int> hash;
            int sameX = 0;
            int samePoint = 0;
            Point p = points[i];
            for(int j = i + 1; j < points.size(); j++){
                Point& cur = points[j];
                if(cur.x == p.x){
                    if(cur.y == p.y){
                        samePoint++;
                    }else{
                        sameX++;
                    }
                }
                else{
                    auto ret = slope(p, cur);
                    if(hash.find(ret) == hash.end()){hash[ret] = 2;}
                    else{
                        hash[ret]++;
                    }
                }
            }
            result = max(result, sameX + 1 + samePoint);
            for(auto item : hash){
                result = max(result, item.second + samePoint);
            }
        }
        
        return result;
    }
};