#include <bits/stdc++.h>
using namespace std;

struct Edge{
    long to;
    long lineNum;
};
class TrainGraph{
    public:
    vector<vector<Edge>> adjMap;
    TrainGraph(long n) : adjMap(n) {}

    void addEdge(long u, long v, long lineNum){
        adjMap[u].push_back({v, lineNum});
        adjMap[v].push_back({u, lineNum});
    }

    const vector<Edge>& getAdj(long u){
        return adjMap[u];
    }
};

int main(){
    long cityCount, lineCount;
    cin >> cityCount >> lineCount;
    TrainGraph graph(cityCount+1);
    for(long i = 0; i < lineCount; i++){
        long u, v;
        cin >> u >> v;
        graph.addEdge(u, v, i+1);
    }

    for(long i = 1; i <= cityCount; i++){ //drop 0, indexed from 1
        if (graph.adjMap[i].size() != 2){
            cout << "impossible" << endl;
            return 0;
        }
    }
    vector<long> route;
    vector<long> lines;
    long current = 1;
    long prev = -1;
    route.push_back(current);

    do{
        for(const Edge& edge : graph.getAdj(current)){
            if (edge.to != prev){
                lines.push_back(edge.lineNum);
                prev = current;
                current = edge.to;
                route.push_back(current);
                break;
            }
        }
    }while (current != 1);

    if (route.size()-1 != cityCount){
        cout << "impossible" << endl;
        return 0;
    }
    for(long line : lines){
        cout<< line << "\n";
    }
    return 0;
}