class MinStack {
    vector<int> vec;
    vector<int> minVal;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        vec.push_back(number);
        if(minVal.empty()){minVal.push_back(number);}
        else if(minVal.back() >= number){
            minVal.push_back(number);
        }
    }

    int pop() {
        // write your code here
        int result = vec.back();
        vec.pop_back();
        if(result == minVal.back()){
            minVal.pop_back();
        }
        return result;
    }

    int min() {
        // write your code here
        return minVal.back();
    }
};
