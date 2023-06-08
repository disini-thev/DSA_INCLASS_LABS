#include <vector>
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

void MST(int v, vector<vector<int>>& adjMatrix){
    //initialize the pq
    //<pair<int,int> <= data type in the priority queue
    //vector<pair<int,int>> <=underlying container of the priority queue
    //greater<pair<int,int>> <=min heap
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector <int> visited(v,0);
    //weight, node,parent
    pq.push({0,0,0});
    //sum of the MST
    int sum=0;
    vector<vector<int>> MST;

    while (!pq.empty()){
        int weight=pq.top()[0];
        int node=pq.top()[1];
        int parent=pq.top()[2];
        pq.pop();

        if (visited[node]==1)   continue;
        //else
        //the edge will be added only if the vertex is not visited only
        visited[node]=1;
        sum+=weight;
        MST.push_back({parent, node});

        for (int i=0; i<v; i++){
            //int adjNode=i
            int adjWeight=adjMatrix[node][i];

            //each neighbour will be added only if that is not visited yet
            if (adjWeight!=INT_MAX && !visited[i]){
                pq.push({adjWeight, i,node});
            }
        }
    }
    for(int i=1; i<v; i++){
        cout<<MST[i][0]<<" -> "<<MST[i][1]<<endl;
    }
    cout<<sum<<endl;
}


int main(){
    vector<vector<int>> adjMatrix={
        {0, 3, INT_MAX, INT_MAX, INT_MAX, 1},
        {3, 0, 2, 1, 10, INT_MAX},
        {INT_MAX, 2, 0, 3, INT_MAX, 5},
        {INT_MAX, 1, 3, 0, 5, INT_MAX},
        {INT_MAX, 0, INT_MAX, 5, 0, 4},
        {1, INT_MAX, 5, INT_MAX, 4, 0}};

    MST(6, adjMatrix);
    return 0;
}
