#pragma once
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>

class Graph
{
public:
    enum class ConnectionType
    {
        undirected,
        directed
    };

    Graph(int vertices, ConnectionType type = ConnectionType::undirected)
            : m_vertices(vertices), m_connectionType(type) {}

    virtual void addEdge(int v, int w) = 0;
    virtual void BFS(int vertex = 0) {};
    virtual void DFS(int vertex = 0) {};
    virtual int numberOfNodesInLevel(int level) const { return 0; }
    virtual bool isStronglyConnected() const { return false; }

protected:
    unsigned int m_vertices;
    ConnectionType m_connectionType;
};

class GraphAdjList : public Graph
{
public:
    GraphAdjList(int vertices, ConnectionType type = ConnectionType::undirected);
    void addEdge(int v, int w) override;
    void BFS(int vertex = 0) override;
    int numberOfNodesInLevel(int level) const override;
    bool isStronglyConnected() const override;

private:
    std::vector<std::list<int>> m_list;
};

GraphAdjList::GraphAdjList(int vertices, ConnectionType type)
        : Graph(vertices, type)
{
    m_list.resize(vertices);
}

void GraphAdjList::addEdge(int v, int w)
{
    m_list[v].push_back(w);
    if (m_connectionType == ConnectionType::undirected)
    {
        m_list[w].push_back(v);
    }
}

void GraphAdjList::BFS(int vertex)
{

}

int GraphAdjList::numberOfNodesInLevel(int level) const
{
    if (level < 0)
    {
        return 0;
    }

    std::vector<bool> visited(m_vertices, false);
    std::queue<int> queue;
    int currentLevel = 0;
    int nodesInCurrentLevel = 0;

    visited[0] = true;
    queue.push(0);

    while (!queue.empty())
    {
        int size = queue.size();

        for (int i = 0; i < size; ++i)
        {
            int currentVertex = queue.front();
            queue.pop();

            if (currentLevel == level)
            {
                nodesInCurrentLevel++;
            }

            for (const int &neighbor : m_list[currentVertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }

        currentLevel++;
        if (currentLevel > level)
        {
            break;
        }
    }

    return nodesInCurrentLevel;
}

bool GraphAdjList::isStronglyConnected() const
{

}

int main()
{
    GraphAdjList graph(10);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);

    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);
    graph.addEdge(3, 7);

    graph.addEdge(4, 8);
    graph.addEdge(5, 9);
    graph.addEdge(7, 10);
    graph.addEdge(6, 9);
    graph.addEdge(1, 9);
    graph.addEdge(1, 3);

    graph.BFS();


}

