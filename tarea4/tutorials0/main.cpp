#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include "Snap.h"
#define INF 1000000
using namespace std;

int main(){
  PUNGraph g=TSnap::LoadEdgeList<PUNGraph>("../facebook_combined.txt",0,1);
  int nodes;
  nodes = g->GetNodes();

  printf("%d\n", nodes);


  return 0;
}
