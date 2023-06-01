#include <iostream>
#include<list>
#include <vector>
#include <queue>
using namespace std;

int dijkstra(vector<vector<pair<int,int>>> &adjList, int n, int startNode){

    int TimeArr[n];  // array to store the shortest distance to all the nodes from the start node
    //initialize every node to unvisited and mark the time as infinity
    for (int i=0; i<n; i++){
        TimeArr[i]=INT_MAX;
    }
    //set the time to the source as zero
    TimeArr[startNode]=0;

    //pq will store the edge weight and the source
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,startNode});

    while(!pq.empty()){
        int currTime= pq.top().first;
        int currSource= pq.top().second;
        pq.pop();

        for ( pair<int,int> neighbour : adjList[currSource]){
            if (currTime + neighbour.second < TimeArr[neighbour.first] ){
                TimeArr[neighbour.first]=currTime+ neighbour.second;
                pq.push({TimeArr[neighbour.first],neighbour.first});
            }

        }

    }
    int ret=0;
    for (int i=0;i<n;i++){
        ret+=TimeArr[i];
        cout<<"Time from " <<startNode<<" => "<<i<<" = "<<TimeArr[i]<<endl;
    }
    return ret;
};

int main(){
    int n=6; //no of nodes
    //pair<int, int> ==pair <neighbour, time>
    //vector <pair<int, int>> = vector of neighbour pairs
    //vector <vector<pair<int,int>>> vector of the neighbour pairs of all the nodes
    vector <vector<pair<int,int>>> adjList ={
        {{1,10},{4,15},{5,5}},
        {{0,10},{2,10},{3,30}},
        {{1,10},{4,5},{3,12}},
        {{1,30},{2,12},{5,20}},
        {{0,15},{2,5}},
        {{0,5},{3,20}}};
    double sourceTime[6];
    for (int i=0; i<n; i++){
        cout<<"Source = "<<i<<endl;
        int minTime=dijkstra(adjList, n, i);
        cout<<"Total Time : "<<minTime<<endl;
        double avgTime=(double)minTime/(n-1);
        sourceTime[i]=avgTime;

    }
    double best=sourceTime[0];
    for (int i=1; i<n; i++){
        if (sourceTime[i]<best) best=sourceTime[i];
    }
    cout<<"Best Average Time "<<best<<endl;
    for (int i=0; i<n; i++){
        if (sourceTime[i]==best) cout<<i<<" ";
    }


};
