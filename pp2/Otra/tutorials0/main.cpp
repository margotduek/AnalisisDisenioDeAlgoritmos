#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include "Snap.h"
#define INF 1000000



const int NUM_NODES = 15;
PNGraph graph ;
int vVal[NUM_NODES][NUM_NODES];

void insertNode(int);
void insertVertex(int, int, int);
void delNode(int);
void delVertex(int, int);
void DFS(bool[], int);
void BFS(int);
void Dijkstra(int);
void Floyd();
void Prim();
void Kruskal();


std::vector<std::pair<int,int> > getChildIds(int);



int main(){
  graph = TNGraph::New();
	for (int i = 1; i < NUM_NODES; ++i)
    insertNode(i);
    insertVertex(1 ,3 ,8);
    insertVertex(1 ,4 ,8);
    insertVertex(2 ,5 ,7);
    insertVertex(3 ,2 ,7);
    insertVertex(3 ,5 ,8);
    insertVertex(3 ,10,4);
    insertVertex(4 ,5 ,1);
    insertVertex(4 ,7 ,3);
    insertVertex(4 ,8 ,2);
    insertVertex(5 ,6 ,9);
    insertVertex(6 ,13,4);
    insertVertex(7 ,4 ,6);
    insertVertex(8 ,7 ,3);
    insertVertex(8 ,9 ,3);
    insertVertex(9 ,10,2);
    insertVertex(9 ,12,4);
    insertVertex(10,3 ,10);
    insertVertex(10,6 ,6);
    insertVertex(11,12,6);
    insertVertex(12,9 ,2);
    insertVertex(12,11,8);
    insertVertex(12,14,9);
    insertVertex(13,14,6);
    insertVertex(14,13,2);

    //Ejecutar algoritmos
    bool visited[NUM_NODES];
    std::fill(visited, visited+NUM_NODES, false);

    //DFS
    std::cout << "\n\n DFS " << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    DFS(visited,1);
    auto end = std::chrono::high_resolution_clock::now();
    auto dfs = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Tiempo de DFS:  " << dfs.count() << std::endl;


    //BFS
    std::cout << "\n\n BFS " << std::endl;
    start = std::chrono::high_resolution_clock::now();
    BFS(1);
    end = std::chrono::high_resolution_clock::now();
    auto bfs = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Tiempo de BFS:  " << bfs.count() << std::endl;


    //Prim
    std::cout << "\n\n Prim " << std::endl;
    start = std::chrono::high_resolution_clock::now();
    Prim();
    end = std::chrono::high_resolution_clock::now();
    auto Prim = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Tiempo de Prim:  " << Prim.count() << std::endl;

    //Kruskal
    std::cout << "\n\n Kruskal " << std::endl;
    start = std::chrono::high_resolution_clock::now();
    Kruskal();
    end = std::chrono::high_resolution_clock::now();
    auto Kruskal = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Tiempo de Kruskal:  " << Kruskal.count() << std::endl;

    //Dijkstra
    std::cout << "\n\n Dijkstra " << std::endl;
    start = std::chrono::high_resolution_clock::now();
    Dijkstra(1);
    end = std::chrono::high_resolution_clock::now();
    auto Dijkstra = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Tiempo de Dijkstra:  " << Dijkstra.count() << std::endl;

    //Floyd
    std::cout << "\n\n Floyd " << std::endl;
    start = std::chrono::high_resolution_clock::now();
    Floyd();
    end = std::chrono::high_resolution_clock::now();
    auto Floyd = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Tiempo de Floyd:  " << Floyd.count() << std::endl;

}

void DFS(bool visited[], int actId){
  if (!visited[actId]){
  std::cout << actId << std::endl;
    visited[actId] = true;
    std::vector<std::pair<int,int> > childs = getChildIds(actId);

    for (int i = 0; i < childs.size(); i++)
      DFS(visited,childs.at(i).first);
  }
}

void BFS(int startId){
  std::queue<std::pair<int,int>> q;
    bool visited[NUM_NODES];
    std::fill(visited, visited+NUM_NODES, false);
    q.push(std::make_pair(startId,0));

    while (!q.empty()){
        int actId = q.front().first;
        q.pop();
        if (!visited[actId]){
          std::cout << actId << std::endl;
          std::vector<std::pair<int,int> > childs = getChildIds(actId);
            for (int i = 0; i < childs.size(); i++){
                q.push(childs.at(i));
            }
        }
        visited[actId] = true;
    }
}

void Dijkstra(int startId){
  std::queue<std::pair<int,int>> q;
    bool visited[NUM_NODES];
    int distances[NUM_NODES];
    std::fill(visited, visited+NUM_NODES, false);
    std::fill(distances, distances+NUM_NODES,INF);

    q.push(std::make_pair(startId,0));
    distances[startId] = 0;

    while (!q.empty()){
        int actId = q.front().first;
        q.pop();
        if (!visited[actId]){
          std::vector<std::pair<int,int> > childs = getChildIds(actId);
            for (int i = 0; i < childs.size(); i++){
                if (distances[actId] + childs.at(i).second < distances[childs.at(i).first]){
                    distances[childs.at(i).first] = distances[actId] + childs.at(i).second;
                    q.push(childs.at(i));
                }
            }
        }
        visited[actId] = true;
    }

    for (int i = 1; i < NUM_NODES; i++){
      std::cout << "del nodo " << i << "  :   ";
        if (distances[i] == INF) std::cout << "INF";
        else std::cout << distances[i];
        std::cout << std::endl;
    }
}

void Floyd(){
    int table[NUM_NODES][NUM_NODES];
    for (int j = 1; j < NUM_NODES; j++){
        for (int i = 1; i < NUM_NODES; i++){
            table[i][j] = vVal[i][j];
            if (table[i][j] == 0) table[i][j] = INF;
            if (i == j) table[i][j] = 0;
        }
    }

    for (int z = 1; z < NUM_NODES; z++){
        for (int j = 1; j < NUM_NODES; j++){
            for (int i = 1; i < NUM_NODES; i++){
                if (table[z][j] + table[i][z]< table[i][j]){
                    table[i][j] = table[z][j] + table[i][z];
                }
            }
        }
        std::cout << "\n\n\niteracion: " << z << std::endl;
        for (int j = 1; j < NUM_NODES; j++){
            for (int i = 1; i < NUM_NODES; i++){
                if (table[i][j] == INF) std::cout << "°°";
                else{
                    if (table[i][j] == 0) std::cout << "\\";
                    else std::cout << std::setfill('0') << std::setw(2) << table[i][j];
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
}



void Prim(){
    std::queue<std::pair<int,int>> q;
    bool visited[NUM_NODES];
    int distances[NUM_NODES];
    std::fill(visited, visited+NUM_NODES, false);
    std::fill(distances, distances+NUM_NODES,INF);
    int startId = 4;
    q.push(std::make_pair(startId,0));
    distances[startId] = 0;

    while (!q.empty()){
        int actId = q.front().first;
        q.pop();
        if (!visited[actId]){
          std::vector<std::pair<int,int> > childs = getChildIds(actId);

            for (int i = 0; i < childs.size(); i++){
                q.push(childs.at(i));
            }
            std::cout << actId << " ";
        }
        visited[actId] = true;
    }
    std::cout << std::endl;

}


bool findInVector(std::vector<int> v, int val){
    for (int i = 0; i < v.size(); i++)
        if (v.at(i) == val)
            return true;
    return false;
}

bool isInVector(std::vector<int> c, std::vector<int> v){
     for (int i = 0; i < v.size(); i++)
        if (findInVector(c,v.at(i))) return true;
    return false;
}

void joinCluster(std::vector<int>& c, std::vector<int> v){
    for (int i = 0; i < v.size(); i++)
        if (!findInVector(c,v.at(i)))
            c.insert(c.begin(),v.at(i));
}


void Kruskal(){
  std::vector<std::vector<int> > q;
  std::vector<std::vector<int> > clusters;

    for (int j = 1; j < NUM_NODES; j++){
        for (int i = 1; i < NUM_NODES; i++){
            if (vVal[i][j] != 0){
              std::vector<int> cluster;
                cluster.push_back(i);
                cluster.push_back(j);
                clusters.push_back(cluster);
            }
        }
    }
     for (int j = 0; j < clusters.size(); j++){
        for (int i = 0; i < clusters.size(); i++){
            if (vVal[clusters.at(i).at(0)][clusters.at(i).at(1)] > vVal[clusters.at(j).at(0)][clusters.at(j).at(1)]){
              std::vector<int> auxC = clusters.at(i);
                clusters.at(i) = clusters.at(j);
                clusters.at(j) = auxC;
            }
        }
    }

    for (int i = 0; i < clusters.size(); i++){
        q.push_back(clusters.at(i));
    }

    std::vector<int> res;
    int it = 0;
    while (q.size() > 1){
      std::vector<int> l  = q.at(0);
        bool join = false;
        for (int i = 1; i < q.size() && !join; i++){
          std::vector<int> ll = q.at(i);
          if (isInVector(l,ll)){
            std::cout << "{";
              for (int i = 0; i < l.size(); i++)
              std::cout << l.at(i) << (i < l.size() -1 ? "," : "");
              std::cout << "} {";
                for (int i = 0; i < ll.size(); i++)
                std::cout << ll.at(i) << (i < l.size() -1 ? "," : "");
                std::cout << "} ";

                joinCluster(l,ll);
                q.erase(q.begin());
                q.erase(q.begin());
                q.push_back(l);
                std::cout << " -->  {";
                for (int i = 0; i < l.size(); i++)
                std::cout << l.at(i) << (i < l.size() -1 ? "," : "");
                std::cout << "} " << std::endl;
                join = true;
             }

        }
        it++;

    }
    std::cout << std::endl;

}


void sortChilds(std::vector<std::pair<int,int> >& childs){
    sort(childs.begin(), childs.end(),
        [](const std::pair<int,int> & a, const std::pair<int,int> & b) -> bool
    {
    return a.second > b.second;
    });
}

std::vector<std::pair<int,int> > getChildIds(int id){
  std::vector<std::pair<int,int> > childs;
    TNGraph::TNodeI nodeI = graph->GetNI(id);
    for (int i = 1; i < NUM_NODES; i++){
        if (nodeI.IsOutNId(i)){
            childs.push_back(std::make_pair(i,vVal[id][i]));
        }
    }
    sortChilds(childs);
    return childs;
}


void insertNode(int id){
    graph->AddNode(id);
}

void insertVertex(int srcId, int desId, int value){
    graph->AddEdge(srcId, desId);
    vVal[srcId][desId] = value;
}

void delNode(int id){
    graph->DelNode(id);
}
void delVertex(int srcId, int desId){
    graph->DelEdge(srcId, desId);
    vVal[srcId][desId] = 0;
}
