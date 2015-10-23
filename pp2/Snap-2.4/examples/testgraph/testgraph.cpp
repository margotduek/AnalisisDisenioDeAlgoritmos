#include "stdafx.h"

int main(int argc, char* argv[]) {
  //// what type of graph do you want to use?
  //typedef PUNGraph PGraph; // undirected graph
  typedef PNGraph PGraph;  //   directed graph
  //typedef PNEGraph PGraph;  //   directed multigraph
  //typedef TPt<TNodeNet<TInt> > PGraph;
  //typedef TPt<TNodeEdgeNet<TInt, TInt> > PGraph;

  // this code is independent of what particular graph implementation/type we use
  printf("Creating graph:\n");
  PGraph G = PGraph::TObj::New();
  for (int n = 0; n < 15; n++) {
    G->AddNode(); // if no parameter is given, node ids are 0,1,...,9
  }
  G->AddEdge(1, 4);
  printf("  Edge 1 -- 4 added\n");
  G->AddEdge(1, 3);
  printf("  Edge 1 -- 3 added\n");
  G->AddEdge(2, 5);
  printf("  Edge 2 -- 5 added\n");
  G->AddEdge(3, 2);
  printf("  Edge 3 -- 2 added\n");
  G->AddEdge(3, 5);
  printf("  Edge 3 -- 5 added\n");
  G->AddEdge(3, 10);
  printf("  Edge 3 -- 10 added\n");
  G->AddEdge(4, 5);
  printf("  Edge 4 -- 5 added\n");
  G->AddEdge(4, 7);
  printf("  Edge 4 -- 7 added\n");
  G->AddEdge(4, 8);
  printf("  Edge 4 -- 8 added\n");
  G->AddEdge(5, 6);
  printf("  Edge 5 -- 6 added\n");
  G->AddEdge(6, 13);
  printf("  Edge 6 -- 13 added\n");
  G->AddEdge(7, 4);
  printf("  Edge 7 -- 4 added\n");
  G->AddEdge(8, 7);
  printf("  Edge 8 -- 7 added\n");
  G->AddEdge(8, 9);
  printf("  Edge 8 -- 9 added\n");
  G->AddEdge(9, 10);
  printf("  Edge 9 -- 10 added\n");
  G->AddEdge(9, 12);
  printf("  Edge 9 -- 12 added\n");
  G->AddEdge(10, 3);
  printf("  Edge 10 -- 3 added\n");
  G->AddEdge(10, 6);
  printf("  Edge 10 -- 6 added\n");
  G->AddEdge(11, 12);
  printf("  Edge 11 -- 12 added\n");
  G->AddEdge(12, 9);
  printf("  Edge 12 -- 9 added\n");
  G->AddEdge(12, 11);
  printf("  Edge 12 -- 11 added\n");
  G->AddEdge(12, 14);
  printf("  Edge 12 -- 14 added\n");
  G->AddEdge(13, 14);
  printf("  Edge 13 -- 14 added\n");
  G->AddEdge(14, 13);
  printf("  Edge 14 -- 13 added\n");

  /*for (int e = 0; e < 10; e++) {
    const int NId1 = G->GetRndNId();
    const int NId2 = G->GetRndNId();
    if (G->AddEdge(NId1, NId2) != -2) {
      printf("  Edge %d -- %d added\n", NId1,  NId2); }
    else {
      printf("  Edge %d -- %d already exists\n", NId1, NId2); }
  }*/
  IAssert(G->IsOk());
  //G->Dump();
  // delete
  //PGraph::TObj::TNodeI NI = G->GetNI(0);
  //printf("Delete edge %d -- %d\n", NI.GetId(), NI.GetOutNId(0));
  //G->DelEdge(NI.GetId(), NI.GetOutNId(0));
  const int RndNId = G->GetRndNId();
  printf("Delete node %d\n", RndNId);
  G->DelNode(RndNId);
  IAssert(G->IsOk());
  // dump the graph
  printf("Graph (%d, %d)\n", G->GetNodes(), G->GetEdges());
  for (PGraph::TObj::TNodeI NI = G->BegNI(); NI < G->EndNI(); NI++) {
    printf("  %d: ", NI.GetId());
    for (int e = 0; e < NI.GetDeg(); e++) {
      printf(" %d", NI.GetNbrNId(e)); }
    printf("\n");
  }
  // dump subgraph
  TIntV NIdV;
  for (PGraph::TObj::TNodeI NI = G->BegNI(); NI < G->EndNI(); NI++) {
    if (NIdV.Len() < G->GetNodes()/2) { NIdV.Add(NI.GetId()); }
  }
  PGraph SubG = TSnap::GetSubGraph(G, NIdV);
  //SubG->Dump();
  // get NGraph
  { PNGraph NG = TSnap::ConvertGraph<PNGraph>(SubG);
  NG->Dump();
  IAssert(NG->IsOk());
  TSnap::ConvertSubGraph<PNGraph>(G, NIdV)->Dump(); }
  // get NEGraph
  { PNEGraph NEG = TSnap::ConvertGraph<PNEGraph>(SubG);
  NEG->Dump();
  IAssert(NEG->IsOk());
  TSnap::ConvertSubGraph<PNGraph>(G, NIdV)->Dump(); }

  TSnap::TestAnf<PUNGraph>();
  return 0;
}

void TestEigSvd() {
  PNGraph G = TSnap::GenRndGnm<PNGraph>(100,1000, true);
  PUNGraph UG = TSnap::ConvertGraph<PUNGraph>(G);

  TSnap::SaveMatlabSparseMtx(G, "test1.mtx");
  TSnap::SaveMatlabSparseMtx(UG, "test2.mtx");

  TFltV SngValV; TVec<TFltV> LeftV, RightV;
  TSnap::GetSngVec(G, 20, SngValV, LeftV, RightV);
  printf("Singular Values:\n");
  for (int i =0; i < SngValV.Len(); i++) {
    printf("%d\t%f\n", i, SngValV[i]()); }
  printf("LEFT Singular Vectors:\n");
  for (int i=0; i < LeftV[0].Len(); i++) {
    printf("%d\t%f\t%f\t%f\t%f\t%f\n", i, LeftV[0][i](), LeftV[1][i](), LeftV[2][i](), LeftV[3][i](), LeftV[4][i]());
  }
  printf("RIGHT Singular Vectors:\n");
  for (int i=0; i < RightV[0].Len(); i++) {
    printf("%d\t%f\t%f\t%f\t%f\t%f\n", i, RightV[0][i](), RightV[1][i](), RightV[2][i](), RightV[3][i](), RightV[4][i]());
  }
  TFltV EigValV;
  TVec<TFltV> EigV;
  TSnap::GetEigVec(UG, 20, EigValV, EigV);
  printf("Eigen Values:\n");
  for (int i =0; i < EigValV.Len(); i++) {
    printf("%d\t%f\n", i, EigValV[i]()); }
  printf("Eigen Vectors %d:\n", EigV.Len());
  for (int i =0; i < EigV[0].Len(); i++) {
    printf("%d\t%f\t%f\t%f\t%f\t%f\n", i, EigV[0][i](), EigV[1][i](), EigV[2][i](), EigV[3][i](), EigV[4][i]());
  }

}
