//
//  BipartiteGraph.h
//  SpotifyProblem3
//
//  Created by Carlos Olave (Mr. Peru).
//  Copyright (c) 2013 Carlos Olave. All rights reserved.
//

#ifndef __SpotifyProblem3__BipartiteGraph__
#define __SpotifyProblem3__BipartiteGraph__
#define NIL 0
#define INF -1000000

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

class BipartiteGraph {

    std::map<int, std::set<int>> G; // Bipartite Graph G = (G1 U G2)
    std::set<int> G1;
    std::set<int> G2;
    std::map<int, int> match;
    std::map<int, int> dist;
    
    // Depth First Search
    bool PartialDFS(int u);
    
    // Breadth First Search
    bool MaximalSetOfPaths();
    
public:
    
    // Constructor.
    BipartiteGraph();
    
    // Destructor.
    ~BipartiteGraph();
    
    // Add edge
    void AddEdge(int u, int v);
    
    // Add vextex to G1
    void AddVertexG1(int g);
    
    // Add vertex to G2
    void AddVertexG2(int g);
    
    // Find maximum matching using Hopcroft-Karp algorithm.
    int HopcroftKarpAlgorithm();
    
    // For not complete bipartite graph... to be implemented.
    int BellmanFordAlgorithm();
};

#endif /* defined(__SpotifyProblem3__BipartiteGraph__) */
