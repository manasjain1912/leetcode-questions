class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        
        stack<int>stk;
        int i=0;
        
        while(i<arr.size())
        {
            if(stk.size()==0)  
            {
                stk.push(arr[i]);
                i++;
            } 
            else if(stk.size()>0)
            {
                int currval=arr[i];
                
                if((stk.top()<0 and currval>0) or (stk.top()>0 and currval<0))  
                {
                    if(stk.top()<0 and currval>0)
                    {
                        stk.push(arr[i]);
                        i++;
                        continue;
                    }
                    else if(abs(stk.top())>abs(currval))
                    {
                       i++;
                    }
                    else if(abs(stk.top())<abs(currval))
                    {
                       stk.pop(); 
                    }
                    else if(abs(stk.top())==abs(currval))
                    {
                        stk.pop();
                        i++;
                    }
                }
                else
                {
                   stk.push(currval);    
                   i++;
                }
            }
        }
        vector<int>ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};