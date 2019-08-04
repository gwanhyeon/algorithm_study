//
//  Adjacency-matrix2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

// 인접 리스트 구현 시간복잡도 O(E)
int main(void){
    
    vector<int> a[10];
    int n;      // vertex
    int m;      // edge
    
    cin >> n >> m;
    // edge의 개수만큼 반복
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        
        a[v].push_back(u);
        a[u].push_back(v);
        
    }

    return 0;
}
