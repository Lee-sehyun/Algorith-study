#include <iostream>

using namespace std;

class graph
{
private:
    int **Graph;
    int size_n;
    int size_m;

public:
    graph(int n = 0, int m = 0)
    {
        Graph = new int *[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            Graph[i] = new int[m + 1];
        }
        size_n = n + 1;
        size_m = m + 1;
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                Graph[i][j] = 0;
            }
        }
    }
    ~graph()
    {
        for (int i = 0; i < size_n; i++)
        {
            delete Graph[i];
        }
        delete Graph;
    }
    void add(int u, int v, int w = 1)
    {
        // 무방향
        Graph[u][v] = Graph[v][u] = w;

        // 단방향
        // Graph[u][v] = w;
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
                    cout << Graph[i][j] << " ";
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