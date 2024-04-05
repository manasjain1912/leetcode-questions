class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++){

            if(st.empty())

                st.push(s[i]);

            else{

                int x = abs(s[i]-st.top());

                if( x == 32)

                    st.pop();

                else

                    st.push(s[i]);

                

            }

        }

        string str="";

        while(!st.empty()){

            str = st.top() + str;

            st.pop();

        }

        

        return str;
    }
};