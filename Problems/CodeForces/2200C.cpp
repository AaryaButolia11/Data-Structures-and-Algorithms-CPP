int t;
cin >> t;
while (t--)
{ // for each test case
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<char> st; // our stack

    for (char c : s)
    {                      // go through each character
        if (!st.empty() && // if stack has something
            st.top() == c) // AND top matches current char
            st.pop();      // POP! they cancel each other
        else
            st.push(c); // no match, push onto stack
    }

    // if stack empty, everything got paired → WIN
    cout << (st.empty() ? "YES" : "NO") << "\n";
}