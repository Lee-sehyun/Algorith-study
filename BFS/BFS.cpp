#include <iostream>
#include <queue>

using namespace std;

vector<vector<int> > graph;
vector<int> check;

void Graph(int size)
{
    for (int i = 0; i < size; i++)
    {
        vector<int> g;
        graph.push_back(g);
        check.push_back(0);
    }
}

void add(int v, int w)
{
    graph[v].push_back(w);
}

void BFS(int FirstNode)
{
    queue<int> q;
    q.push(FirstNode);

    while (!q.empty())
    {
        int thisNode = q.front();
        q.pop();
        if (check[thisNode] == 0)
        {
            for (int i = 0; i < graph[thisNode].size(); i++)
            {
                q.push(graph[thisNode][i]);
            }
            cout << thisNode << " ";
            check[thisNode] = 1;
        }
    }
}

int main()
{
    Graph(5);
    add(0, 2);
    add(0, 4);
    add(1, 2);
    add(1, 4);
    add(2, 3);
    add(2, 4);
    add(3, 4);
    add(4, 1);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    BFS(0);
    cout << endl;
}