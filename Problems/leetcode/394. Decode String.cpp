class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(char ch : s) {

            if(ch != ']') {
                st.push(ch);
            }
            else {
                // Extract string inside []
                string curr = "";

                while(!st.empty() && st.top() != '[') {
                    curr += st.top();
                    st.pop();
                }

                reverse(curr.begin(), curr.end());

                // Remove '['
                st.pop();

                // Extract number
                string num = "";

                while(!st.empty() && isdigit(st.top())) {
                    num += st.top();
                    st.pop();
                }

                reverse(num.begin(), num.end());

                int k = stoi(num);

                string decoded = "";
                while(k--) {
                    decoded += curr;
                }

                // Push decoded string back
                for(char c : decoded) {
                    st.push(c);
                }
            }
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};