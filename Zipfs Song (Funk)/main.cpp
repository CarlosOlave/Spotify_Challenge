//
//  main.cpp
//  SpotifyProblem2
//
//  Created by Carlos Olave (Mr. Peru).
//  Copyright (c) 2013 Carlos Olave. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "main.h"

// Sorting function.
bool CompareData(const song& A, const song& B)
{
    return A.playCount > B.playCount;
}

int main(int argc, const char * argv[])
{
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    song *songCollection = new song[n];
    double fi = 0;
    char* si;
    double ith = 1;
    for (int i=0; i<n; i++) {
    
        si = new char[30];
        std::cin >> fi >> si;
        songCollection[i].playCount = (fi/(1/ith));
        songCollection[i].name = si;
        ith++;
    }
    
    // Requirement: If two songs have the same quality, give precedence
    // to the one appearing first on the album.
    std::stable_sort(songCollection, songCollection+n, &CompareData);
    
    // Simple output result.
    for (int j=0; j<m; j++) {
    
        std::cout << songCollection[j].name << std::endl;
    }
    
    delete []songCollection;
}

