class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<pair<int,double>> v1;

        for(int i = 0; i < 6; i++){
            v1.push_back(make_pair(i + 1, 1.0 / 6));
        }


        vector<pair<int,double>> result = v1;
        if(n == 1){return result;}

        for(int dices = 2; dices <= n; dices++){
            vector<pair<int, double>> v2 {result};
            result.clear();
            result.resize(dices * 6 - dices + 1);
            int prevShift = dices - 1;
            int curShift = dices;
            for(int cur = dices; cur <= dices * 6; cur++){
                auto& value = result[cur - curShift];
                value = make_pair(cur, 0.0);
                for(int i = 1; i <= 6; i++){
                    int another = cur - i;
                    int anIdx = another - prevShift;
                    if(anIdx < 0 || anIdx >= v2.size()){
                        continue;
                    }
                    double d = v1[i - 1].second * v2[anIdx].second;
                    value.second += d;
                }
            }
        }

        return result;
    }
};
