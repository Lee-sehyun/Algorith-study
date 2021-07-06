class Solution
{
public:
    static bool compare(vector<int> v1, vector<int> v2)
    {
        return abs(v1[1] - v1[0]) > abs(v2[1] - v2[0]);
    }

    int twoCitySchedCost(vector<vector<int> > &costs)
    {

        sort(costs.begin(), costs.end(), compare);
        int result = 0, A = 0, B = 0, n = costs.size() / 2;

        for (int i = 0; i < costs.size(); i++)
        {
            if (A < n && B < n)
            {
                if (costs[i][0] < costs[i][1])
                {
                    result += costs[i][0];
                    A++;
                }
                else
                {
                    result += costs[i][1];
                    B++;
                }
            }
            else
            {
                if (A == n)
                {
                    result += costs[i][1];
                }
                else
                {
                    result += costs[i][0];
                }
            }
        }

        return result;
    }
};