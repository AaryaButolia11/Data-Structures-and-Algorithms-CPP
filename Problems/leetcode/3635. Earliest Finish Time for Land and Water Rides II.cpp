class Solution
{
public:
    int finishTime(vector<int> &s1, vector<int> &d1, vector<int> &s2, vector<int> &d2)
    {
        int fin1 = INT_MAX;
        // find minimum time to cover activity 1
        for (int i = 0; i < s1.size(); i++)
        {
            fin1 = min(fin1, s1[i] + d1[i]);
        }
        int fin2 = INT_MAX;
        // now as ik the activity 1 is completed i want to finish activity2 at earliest
        // so i'll take max of fin1 & start of a2 as i might need to wait for a2 to start if my a1 gets early immediately
        // then i add duration to it of the time spent on a2
        for (int i = 0; i < s2.size(); i++)
        {
            fin2 = min(fin2, max(fin1, s2[i]) + d2[i]);
        }
        // i'll return the time done for completing both a1 and a2
        return fin2;
    }
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int LtoW = finishTime(landStartTime, landDuration, waterStartTime, waterDuration);
        int WtoL = finishTime(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(LtoW, WtoL);
    }
};