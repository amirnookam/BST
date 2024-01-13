#BFS&DFS
#include <iostream>
#include <list>
using namespace std;

class Graf {
private:
    int numVertices;
    vector<std::list<int>> adjLists;
    vector<bool> visited;

    void DFSUtil(int startVertex);
    void BFSUtil(int startVertex);

public:
    Graf(int vertices) : numVertices(vertices), adjLists(vertices), visited(vertices, false) {}

    void addEdge(int src, int dest);

    void DFS(int startVertex) {
        visited.assign(numVertices, false);
        DFSUtil(startVertex);
    }
    void BFS(int startVertex) {
        visited.assign(numVertices, false);
        BFSUtil(startVertex);
    }
};


void Graf::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graf::DFSUtil(int startVertex) {

    visited[startVertex] = true;

    cout << startVertex << " ";

    for (int neighbor : adjLists[startVertex]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor);
        }
    }
}

void Graf::BFSUtil(int startVertex) {

    queue<int> bfsQueue;
    bfsQueue.push(startVertex);
    visited[startVertex] = true;

    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();

        cout << currentVertex << " ";

        for (int neighbor : adjLists[currentVertex]) {
            if (!visited[neighbor]) {
                bfsQueue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    cout << "Enter number : ";
    int gc;
    cin >> gc;

    Graf graf(gv);

    while (true) {

        cout << "Enter number : \n"
             << "1. Add edge \n"
             << "2. BFS \n"
             << "3. DFS \n"
             << "4. Exit \n";

        char selected;
        cin >> selected;

        int src;
        int dest;
        int startVertex;
        switch (selected) {
            case '1':
                cout << "Enter the source: ";
                cin >> src;
                cout << "Enter the destination: ";
                cin >> dest;
                graph.addEdge(src, dest);
                break;

            case '2':
                cout << "Enter the startVertex: ";
                cin >> startVertex;
                graph.BFS(startVertex);
                cout << "\n";
                break;

            case '3':
                cout << "Enter the startVertex: ";
                cin >> startVertex;
                graph.DFS(startVertex);
                cout << "\n";
                break;

            case '4':
                exit(0);

            default:
                cout << "wrong.";
        }
    }
}

