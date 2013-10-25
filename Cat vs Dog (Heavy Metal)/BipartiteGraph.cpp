//
//  BipartiteGraph.cpp
//  SpotifyProblem3
//
//  Created by Carlos Olave (Mr. Peru).
//  Copyright (c) 2013 Carlos Olave. All rights reserved.
//

#include "BipartiteGraph.h"

// Constructor
BipartiteGraph::BipartiteGraph() {
    
};

// Destructor
BipartiteGraph::~BipartiteGraph() {
    
    for (std::map<int, std::set<int>>::iterator it = G.begin(); it != G.end(); ++it)
        it->second.clear();
    
    G.clear();
    G1.clear();
    G2.clear();
    match.clear();
    dist.clear();
};

// Add an edge to the graph
void BipartiteGraph::AddEdge(int u, int v) {
    
    G[u].insert(v);
    if (G.find(v) != G.end())
        G[v].insert(u);
};

// Add vertex to G1
void BipartiteGraph::AddVertexG1(int g) {
    
    G1.insert(g);
};

// Add vertex to G2
void BipartiteGraph::AddVertexG2(int g) {

    G2.insert(g);
};

// Algorithm for finding maximun matching.
int BipartiteGraph::HopcroftKarpAlgorithm() {
    
    int matching = 0;
    
    for (std::set<int>::iterator it=G1.begin();
         it!=G1.end(); ++it)
        match[*it] = NIL;
    
    while(MaximalSetOfPaths())
        for (std::set<int>::iterator it=G1.begin();
             it!=G1.end(); ++it)
            if (match[*it]==NIL && PartialDFS(*it))
                matching++;
    return matching;
};

// Computes augmented paths.
bool BipartiteGraph::PartialDFS(int u) {
    
    int v;
    if(u!=NIL) {
        
        for (std::set<int>::iterator it=G[u].begin();
             it!=G[u].end(); ++it) {
            
            v = *it;
            if(dist[match[v]]==dist[u]+1) {
                if(PartialDFS(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

// Partitions the vertices of the graph into layers.
bool BipartiteGraph::MaximalSetOfPaths() {

    int u, v;
    std::queue<int> freeVertices;
    for (std::set<int>::iterator it=G1.begin();
         it!=G1.end(); ++it) {
        if (match[*it]==NIL) {
            dist[*it] = 0;
            freeVertices.push(*it);
        }
        else
            dist[*it] = INF;
    }
    dist[NIL] = INF;
    
    while(!freeVertices.empty()) {
        
        u = freeVertices.front();
        freeVertices.pop();
        if(u!=NIL) {
            
            for (std::set<int>::iterator it=G[u].begin();
                 it!=G[u].end();
                 ++it) {
                
                v = *it;
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    freeVertices.push(match[v]);
                }
            }
        }
    }
    
    return (dist[NIL]!=INF);
}