// User function Template for C++

int findLength(string s) {
    // code
    int len=0,tail=s.length()-1;
    while(tail>=0 && s[tail]==' ') tail--;
    while(tail>=0 && s[tail]!=' ') 
    {
        len++;
        tail--;
    }
    return len;
}
