class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>res;
        // soln1
        // for(int i=0;i<words.size();i++)
        // {
        //     for(int j=0;j<words[i].size();j++)
        //     {
        //         if(words[i][j]==x)
        //         {
        //             res.push_back(i);
        //             break;
        //         }
        //     }
        // }


        // soln2
        for (int i = 0 ; i < words.size() ; i++) {
            if (count(words[i].begin(), words[i].end(), x)) res.push_back(i);
        }
        return res;
    }
};
