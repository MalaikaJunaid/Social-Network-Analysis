#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "include/csv.hpp"  // Include the csv-parser header

using namespace std;
using namespace csv;

const int MAX_NODES = 50;
const int NO_CONNECTION = -1;
const int INT_INFINITY = 1000000;

class SocialNetworkGraph
{
private:
    int nodeIndex[MAX_NODES];
    string nodeTitles[MAX_NODES];
    int adjacencyMatrix[MAX_NODES][MAX_NODES];

public:
    SocialNetworkGraph()
    {
        for (int i = 0; i < MAX_NODES; ++i)
        {
            nodeIndex[i] = -1;
            nodeTitles[i] = " ";
            for (int j = 0; j < MAX_NODES; ++j)
            {
                adjacencyMatrix[i][j] = NO_CONNECTION;
            }
        }
    }

    void addEdge(const string& source, const string& destination, int weight)
    {
        int sourceIndex = getNodeIndex(source);
        int destIndex = getNodeIndex(destination);
        adjacencyMatrix[sourceIndex][destIndex] = weight;
    }

    int getNodeIndex(const string& nodeName)
    {
        for (int i = 0; i < MAX_NODES; ++i)
        {
            if (nodeIndex[i] == -1)
            {
                nodeIndex[i] = i;
                nodeTitles[i] = nodeName;
                return i;
            }
            else if (nodeName == nodeTitles[i])
            {
                return i;
            }
        }
        return -1;
    }

    void dijkstra(const string& startNode, const string& endNode)
    {
        int startNodeIndex = getNodeIndex(startNode);
        int endNodeIndex = getNodeIndex(endNode);

        int distance[MAX_NODES];
        int previousNode[MAX_NODES];
        bool visited[MAX_NODES] = { false };

        for (int i = 0; i < MAX_NODES; ++i)
        {
            distance[i] = INT_INFINITY;
            previousNode[i] = -1;
        }

        distance[startNodeIndex] = 0;

        for (int count = 0; count < MAX_NODES; ++count)
        {
            int minDistance = INT_INFINITY;
            int minIndex = -1;

            for (int v = 0; v < MAX_NODES; ++v)
            {
                if (!visited[v] && distance[v] < minDistance)
                {
                    minDistance = distance[v];
                    minIndex = v;
                }
            }

            if (minIndex == -1) break;
            visited[minIndex] = true;

            for (int v = 0; v < MAX_NODES; ++v)
            {
                if (!visited[v] && adjacencyMatrix[minIndex][v] != NO_CONNECTION &&
                    distance[minIndex] != INT_INFINITY &&
                    distance[minIndex] + adjacencyMatrix[minIndex][v] < distance[v])
                {
                    distance[v] = distance[minIndex] + adjacencyMatrix[minIndex][v];
                    previousNode[v] = minIndex;
                }
            }

            if (minIndex == endNodeIndex)
            {
                break;
            }
        }

        printShortestPath(startNodeIndex, endNodeIndex, previousNode);
    }

    void printShortestPath(int startNodeIndex, int endNodeIndex, const int previousNode[])
    {
        int path[MAX_NODES];
        int pathLength = 0;

        for (int at = endNodeIndex; at != -1; at = previousNode[at])
        {
            path[pathLength++] = at;
        }

        cout << "Shortest path from " << nodeTitles[startNodeIndex] << " to " << nodeTitles[endNodeIndex] << ": ";

        for (int i = pathLength - 1; i >= 0; --i)
        {
            cout << nodeTitles[path[i]];
            if (i > 0)
            {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    void displayAdjacencyMatrix()
    {
        cout << "Adjacency Matrix:" << endl;
        cout << "   ";
        for (int i = 0; i < MAX_NODES; ++i)
        {
            if (nodeIndex[i] != -1)
            {
                cout << nodeTitles[i] << " ";
            }
        }
        cout << endl;

        for (int i = 0; i < MAX_NODES; ++i)
        {
            if (nodeIndex[i] != -1)
            {
                cout << nodeTitles[i] << " ";
                for (int j = 0; j < MAX_NODES; ++j)
                {
                    if (nodeIndex[j] != -1)
                    {
                        if (adjacencyMatrix[i][j] == NO_CONNECTION)
                        {
                            cout << "INF ";
                        }
                        else
                        {
                            cout << adjacencyMatrix[i][j] << " ";
                        }
                    }
                }
                cout << endl;
            }
        }
    }
};

void readCSVAndPopulateGraph(const string& fileName, SocialNetworkGraph& graph)
{
    CSVReader reader(fileName);
    vector<string> nodeNames;
    bool firstRow = true;

    for (CSVRow& row : reader)
    {
        if (firstRow)
        {
            for (CSVField& field : row)
            {
                if (!field.is_null())
                {
                    nodeNames.push_back(field.get<>());
                }
            }
            firstRow = false;
        }
        else
        {
            string source = row[0].get<>();
            graph.getNodeIndex(source); // Ensure the source node is indexed
            for (size_t i = 1; i < row.size(); ++i)
            {
                string destination = nodeNames[i - 1];
                if (!row[i].is_null() && row[i].is_num())
                {
                    int weight = row[i].get<int>();
                    if (weight != NO_CONNECTION)
                    {
                        graph.addEdge(source, destination, weight);
                    }
                }
            }
        }
    }
}

int main()
{
    SocialNetworkGraph graph;

    // the CSV file
    readCSVAndPopulateGraph("Social_Network_Analysis_Responses.csv", graph);

    graph.displayAdjacencyMatrix();

    graph.dijkstra("A", "D");

    return 0;
}
