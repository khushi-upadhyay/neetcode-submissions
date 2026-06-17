class MinStack {
     stack<int>st;   //actual stack
stack<int>minstack; // auxiliary stack
public:


    MinStack() {
       
        
    }
    
    void push(int val) {
        st.push(val); // st will have noraml push 
        // minstack push 
        if(minstack.empty() || val <= minstack.top()){
            minstack.push(val);
        }
        else{
            // val is greater than the top of minstack so push same minstack.top
            minstack.push(minstack.top());

        }
    }
    
    void pop() {
        // if(st.empty()) return -1;
        // have to everytime pop the top element of st because thats the actual stack
        st.pop();
        // pop from minstack to maintain the st minimum val
        minstack.pop();

        
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
        
    }
    
    int getMin() {
        if(minstack.empty()) return -1;
        return minstack.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



 //https://www.geeksforgeeks.org/dsa/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/


 // at time of pop if in s I have 
//  s-> 16,15,29,19,18(16 is top)
//  minstack -> 15,15,18,18,18
//  min = 15 (minstack.top())
//  now if i do pop then pop from both 
//  so pop 
//  s-> 15,29,19,18
//  minstack-> 15,18,18,18
//  now min will be 15 

//  again pop 
//  s-> 29,19,18
//  minstack-> 18,18,18

//  so now min will be 18 right ??