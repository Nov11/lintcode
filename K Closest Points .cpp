class Solution {
	static long long dis(const Point& p1) {
		return (long long)(p1.x - ori.x) * (p1.x - ori.x) + (p1.y - ori.y) * (p1.y - ori.y);
	}
	static int less(const Point& p1, const Point& p2) {
		long long s1 = dis(p1);
		long long s2 = dis(p2);
		if (s1 == s2) {
			if (p1.x == p2.x) { return p1.y < p2.y; }
			return p1.x < p2.x;
		}
		return s1 < s2;
	}
	static Point ori;
public:
	/*
	* @param points: a list of points
	* @param origin: a point
	* @param k: An integer
	* @return: the k closest points
	*/
	vector<Point> kClosest(vector<Point> points, Point origin, int k) {
		// write your code here
		priority_queue<Point, vector<Point>, decltype(&Solution::less)> p(&Solution::less);
		ori = origin;
		for (auto item : points) {
			p.push(item);
			if (p.size() > k) { p.pop(); }
		}
		vector<Point> result(k);
		for (int i = k - 1; i >= 0; i--) {
			result[i] = p.top();
			p.pop();
		}
		return result;
	}
};

Point Solution::ori;