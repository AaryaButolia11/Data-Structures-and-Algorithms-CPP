class Solution {
public:
    string removeDuplicates(string s){
        // create stack to remove duplicates
        stack<int> st;
        // for each char in str
        for(char c:s){
            // if(st.empty())  st.push(c);

            // if stack isn't empty & top of stack is same as curr i/p
            if(!st.empty() && st.top()==c){
                // pair found so we need to remove it!
                st.pop();
            }
            else{
                // else we need to push the new curr char in the stack
                st.push(c);
            }
        }
        // create string ans to reply.
        string ans;
        // loop till string isnt empty.
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        // reverse string 
        reverse(ans.begin(),ans.end());
        return ans;
    } 
};