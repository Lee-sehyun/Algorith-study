BFS (Breadth-First Searsh)
========================

너비 우선 탐색이란 루트 노드(가장 첫 노드)에서 시작해서 인접한 노드들을 먼저 탐색하는 방법이다.
* 시작지점에서부터 가까운 정점들을 먼저 탐색하고, 멀리 떨어져있는 정점을 나중에 탐색하는 즉, 넓게 탐색하는 순회 방법이다.
* 사용하는 경우
    * 두 노드 사이의 최단 경로를 찾고 싶을 때
    * 임의의 경로를 찾고 싶을 때
* 넓이 우선 탐색(BFS)의 특징
    * 시작 노드에서 시작해서 거리에 따라 단계별로 탐색
    * 재귀적으로 동작하지 않는다.
    * 어떤 노드를 방문 했었는지 여부를 반드시 검사해야한다.
    * 선입선출 원칙으로 탐색하기 때문에 큐(queue)를 사용한다.
* 넓이 우선 탐색(BFS)의 과정
    1. 시작 노드를 방문한다.
    2. 이웃의 노드들을 큐에 삽입한다. 
    3. 큐의 노드를 하나씩 빼서 2번을 반복한다.
    4. 큐가 비어질 때까지 2번부터 반복한다.

구현 예시) 
* [BFS 코드](BFS.cpp)

<pre>
<code>
void BFS(int FirstNode)
{
    queue<int> q;       // --> queue를 이용해서 BFS를 만든다.
    q.push(FirstNode);      // --> 1번

    while (!q.empty())      // --> queue가 비어질때까지 반복한다. (4번)
    {
        int thisNode = q.front();       // --> queue에서 하나를 뺀다.
        q.pop();
        if (check[thisNode] == 0)       // --> 만약 방문하지 않은 노드라면,
        {
            for (int i = 0; i < graph[thisNode].size(); i++)
            {
                q.push(graph[thisNode][i]);         // --> 이웃의 노드를 queue에 넣어준다 (2번)
            }
            cout << thisNode << " ";
            check[thisNode] = 1;        // --> 노드를 방문했음을 체크한다.
        }
    }
}
</code>
</pre>