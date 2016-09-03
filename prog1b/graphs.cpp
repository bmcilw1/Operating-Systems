// Brian McIlwain
// Cracking the C Interview
// Super simple graph implementation via Adjacency list

#include <list>
#include <vector>
#include <iostream>

using std::list;
using std::vector;
using std::cout;
using std::endl;

void dfs(int root, vector<bool> visited);

vector< list<int> > adjList(4);

int main()
{
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[0].push_back(3);
    adjList[1].push_back(3);
    adjList[1].push_back(0);
    adjList[2].push_back(3);

    // Iterate over graph
    for (auto vectit = adjList.begin(); vectit != adjList.end(); ++vectit)
    {
        cout << "vertex: " << vectit - adjList.begin() << " contains a path to: ";

        for (auto listit = vectit->begin(); listit != vectit->end(); ++listit)
        {
            int value = *listit;
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}

void dfs(int root, vector<bool> visited)
{
    
}
