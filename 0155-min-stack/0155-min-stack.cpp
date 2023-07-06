class MinStack {
public:
     stack<pair<int,int>>st;
    MinStack() {
       
    }
    
    void push(int val) {
        int mini;
        if(st.empty())
        {
            mini=val;
        }
        else
        {
            mini=min(val,st.top().second);
        }
         st.push({val,mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

   
     