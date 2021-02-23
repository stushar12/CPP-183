#include<bits/stdc++.h>
using namespace std;

vector<pair<long long int,long long int>> *graph;

void addEdge(long long int x,long long int y,long long int weight)
{
    graph[x].push_back({y,weight});
    graph[y].push_back({x,weight});
}

void prim_mst(long long int vertices)
{
    priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> Q;
    
   long long int visited[vertices+1];
    fill(visited,visited+vertices+1,0);
   long long int ans=0;

    Q.push({0,0});       //weight,destination

    while(!Q.empty())
    {
        auto best=Q.top();          //minimum weight
        Q.pop();

       long long int destination=best.second;
       long long int weight=best.first;

        if(visited[destination]==1)
        {
            continue;
        }

        ans=ans+weight;
        visited[destination]=1;

        for(auto x:graph[destination])
        {
            if(visited[x.first]==0)
        Q.push({x.second,x.first});

        }
    }
    cout<<ans;
}

int main()
{
    long long int vertices,edges;
    cin>>vertices>>edges;
    graph=new vector<pair<long long int,long long int>>[vertices];

    for(long long int i=0;i<edges;i++)
    {
        long long int x,y,weight;
        cin>>x>>y>>weight;
        addEdge(x-1,y-1,weight);
    }
    prim_mst(vertices);
}