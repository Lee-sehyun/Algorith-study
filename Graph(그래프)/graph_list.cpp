#include <iostream>
#include <vector>

using namespace std;

class graph
{
private:
    vector<vector<pair<int, int> > > Graph;
    int size_n;
    int size_m;

public:
    graph(int n = 0, int m = 0)
    {
        size_n = n + 1;
        size_m = m + 1;
        for (int i = 0; i < n + 1; i++)
        {
            Graph.resize(n + 1, vector<pair<int, int> >(0));
        }
    }
    void add(int u, int v, int w = 1)
    {
        // 무방향
        Graph[u].push_back(make_pair(v, w));
        Graph[v].push_back(make_pair(u, w));

        // 단방향
        // Graph[u].push_back(make_pair(v, w));
    }
    void print()
    {
        for (int i = 0; i < size_n; i++)
        {
            for (int j = 0; j < size_m; j++)
            {
                if (i == 0)
                    cout << j << " ";
                else if (j == 0)
                    cout << i << " ";
                else
                {
                    int check = 0;
                    for (vector<pair<int, int> >::iterator iter = Graph[i].begin(); iter != Graph[i].end(); iter++)
                    {
                        if ((*iter).first == j)
                        {
                            cout << (*iter).second << " ";
                            check = 1;
                        }
                    }
                    if (check == 0)
                    {
                        cout << 0 << " ";
                    }
                }
            }
            cout << "\n";
        }
    }
};

int main()
{
    graph my_graph(5, 5);

    my_graph.add(1, 2);
    my_graph.add(1, 3);
    my_graph.add(1, 4);
    my_graph.add(1, 5);
    my_graph.add(2, 3);
    my_graph.add(2, 4);
    my_graph.add(3, 5);
    my_graph.add(4, 5);

    my_graph.print();

    return 0;
}