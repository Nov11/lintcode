class Solution {
public:
    //I can't come up with all these on my own for now.
    /**
     * @param nums an array with positive and negative numbers
     * @param k an integer
     * @return the maximum average
     */
    double maxAverage(vector<int>& nums, int k) {
        // Write your code here
        int len = nums.size();
        double minVal = INT_MAX;
        double maxVal = INT_MIN;
        for(auto item : nums){
            minVal = min(minVal, item * 1.0);
            maxVal = max(maxVal, item * 1.0);
        }
        
        while(maxVal - minVal > 1e-10){
            double mid = minVal + (maxVal - minVal) / 2;
            vector<double> sum(len + 1);
            double minSum = 0;
            bool beLarger = false;
            for(int i = 1; i <= len; i++){
                sum[i] = sum[i - 1] + nums[i - 1] - mid;
                if(i >= k && sum[i] - minSum > 0){
                    beLarger = true;
                    break;
                }
                if(i >= k){
                    minSum = min(minSum, sum[i + 1 - k]);
                }
            }
            if(beLarger){minVal = mid;}
            else{maxVal = mid;}
        }
        
        return minVal;
    }
};