#include <string>
#include <vector>

using namespace std;

int find(char c, string skill);

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++)
    {
        int k = 0;
        for (int j = 0; j < skill.length(); j++)
        {
            int a = find(skill[j], skill_trees[i]);
            if (k != -1)
            {
                if (k > a)
                {
                    if (a == -1)
                        k = -1;
                    else
                        break;
                }
                else
                    k = a;
            }
            else
            {
                if (a != -1)
                    break;
            }
            if (j == skill.length() - 1)
            {
                answer++;
            }
        }
    }
    return answer;
}

int find(char c, string skill)
{
    for (int i = 0; i < skill.length(); i++)
    {
        if (c == skill[i])
            return i + 1;
    }
    return -1;
}