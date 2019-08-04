//
//  Adjacency-matrix.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


int a[10][10];

// 인접 리스트 구현 시간복잡도 O(v^2)
int main(void){
    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
        cout << a[u][v];
        cout << endl;
    }
}
