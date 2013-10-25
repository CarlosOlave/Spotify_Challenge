//
//  main.cpp
//  SpotifyProblem3
//
//  Created by Carlos Olave (Mr. Peru).
//  Copyright (c) 2013 Carlos Olave. All rights reserved.
//

#include <iostream>
#include "BipartiteGraph.h"
#include "main.h"

int main(int argc, const char * argv[]) {
    
    // Number of test cases.
    std::queue<int> result;
    int iTestCases = 0;
    std::cin >> iTestCases;
    std::vector<vote> catLoverCollection;
    std::vector<vote> dogLoverCollection;
    
    // For each test case.
    for (int iTestCaseCount=0; iTestCaseCount<iTestCases; iTestCaseCount++) {
        
        // c, d, v
        int iCats = 0;
        int iDogs = 0;
        int iVoters = 0;
        std::cin >> iCats >> iDogs >> iVoters;
        
        // Create a list of votes. O(N).
        for (int iVoterCount=0; iVoterCount<iVoters; iVoterCount++) {
            
            std::string strKeepPet, strThrowPet;
            std::cin >> strKeepPet >> strThrowPet;
            vote v;
            v.strKeep = strKeepPet;
            v.strThrow = strThrowPet;
            v.iID = iVoterCount + 1;
            
            if (strKeepPet[0] == 'C')
                catLoverCollection.push_back(v);
            else
                dogLoverCollection.push_back(v);
        }
        
        BipartiteGraph graph;
        
        // Create bipartite graph of conflicting votes. O(m1*m2)
        for (std::vector<vote>::iterator it1=catLoverCollection.begin();
             it1!=catLoverCollection.end(); ++it1) {
            
            for (std::vector<vote>::iterator it2=dogLoverCollection.begin();
                 it2!=dogLoverCollection.end();
                 ++it2) {
                
                // Cat lover -> Dog lover OR
                // Dog lover -> Cat lover
                if (it1->strThrow == it2->strKeep ||
                    it2->strThrow == it1->strKeep) {
                    
                    graph.AddVertexG1(it1->iID);
                    graph.AddVertexG2(it2->iID);
                    graph.AddEdge(it1->iID, it2->iID);
                }
            }
        }
        
        // Clear data.
        catLoverCollection.clear();
        dogLoverCollection.clear();
        
        // Compute maximum matching. O(|E|\sqrt{|V|})
        int iMaxiumMatching = graph.HopcroftKarpAlgorithm();
        result.push(iVoters-iMaxiumMatching);
    }
    
    // Print out solution.
    while (!result.empty()) {
        
        std::cout<<result.front()<<std::endl;
        result.pop();
    }
}

