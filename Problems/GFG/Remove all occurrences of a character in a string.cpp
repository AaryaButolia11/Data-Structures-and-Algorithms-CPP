// User function Template for C++
class Solution {
  public:
    // Function to remove all occurrences of the character from the string
    void removeCharacter(string &s, char c) {
        // code here
        int pos=s.find(c);
        while(pos!=string::npos)
        {
            s.erase(pos,1);
            pos=s.find(c);
        }
        // return s;
    }
};
