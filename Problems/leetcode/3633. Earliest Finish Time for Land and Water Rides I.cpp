class Solution
{
    int solve(vector<int> &start1, vector<int> &duration1, vector<int> &start2,
              vector<int> &duration2)
    {
        // finish time of first ride is the minimum of all finish times of rides in first category
        int finish1 = INT_MAX;
        for (int i = 0; i < start1.size(); i++)
        {
            // finish time of a ride is the start time of that ride + duration of that ride
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for (int i = 0; i < start2.size(); i++)
        {
            // finish time of a ride in the second category is the maximum of its start time and the finish time of the first ride + its duration
            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }

public:
    int earliestFinishTime(vector<int> &landStartTime,
                           vector<int> &landDuration,
                           vector<int> &waterStartTime,
                           vector<int> &waterDuration)
    {
        int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};