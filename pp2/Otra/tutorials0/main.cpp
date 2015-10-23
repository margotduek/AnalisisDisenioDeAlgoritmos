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
void printDFS(bool[], int);
void printBFS(int);
void printDijkstra(int);
void printFloyd();

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
    printDFS(visited,1);
    auto end = std::chrono::high_resolution_clock::now();
    auto dfs = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Tiempo de DFS:  " << dfs.count() << std::endl;


    //BFS
    std::cout << "\n\n BFS " << std::endl;
    start = std::chrono::high_resolution_clock::now();
    printBFS(1);
    end = std::chrono::high_resolution_clock::now();
    auto bfs = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Tiempo de BFS:  " << bfs.count() << std::endl;


    //Dijkstra
    std::cout << "\n\n Dijkstra " << std::endl;
    start = std::chrono::high_resolution_clock::now();
    printBFS(1);
    end = std::chrono::high_resolution_clock::now();
    auto Dijkstra = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Tiempo de Dijkstra:  " << Dijkstra.count() << std::endl;

    //Floyd
    std::cout << "\n\n Floyd " << std::endl;
    start = std::chrono::high_resolution_clock::now();
    printFloyd();
    end = std::chrono::high_resolution_clock::now();
    auto Floyd = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Tiempo de Floyd:  " << Floyd.count() << std::endl;

}

void printDFS(bool visited[], int actId){
  if (!visited[actId]){
  std::cout << actId << std::endl;
    visited[actId] = true;
    std::vector<std::pair<int,int> > childs = getChildIds(actId);

    for (int i = 0; i < childs.size(); i++)
      printDFS(visited,childs.at(i).first);
  }
}

void printBFS(int startId){
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

void printDijkstra(int startId){
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

void printFloyd(){
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
