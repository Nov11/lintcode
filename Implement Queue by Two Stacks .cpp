class MyQueue {
    void work(){
        while(!stack1.empty()){
            int tmp = stack1.top();
            stack2.push(tmp);
            stack1.pop();
        }
    }
public:
    stack<int> stack1;
    stack<int> stack2;

    MyQueue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        //not the same as STL library. this pop returns value!!!!!!!
        int ret = top();
        stack2.pop();
        return ret;
    }

    int top() {
        // write your code here
        if(stack2.empty()){
           work();
        }
        
        return stack2.top();
    }
};
