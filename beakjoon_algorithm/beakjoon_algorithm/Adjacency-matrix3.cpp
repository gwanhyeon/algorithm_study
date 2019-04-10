//
//  Adjacency-matrix3.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// 인접 리스트 구현 시간복잡도 O(E)
int main(void){
    int n,m;
    vector<pair<int,int>> a[10];
    
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int u,v,w;      // u-> 정점1
                        // v-> 정점2
                        // w-> 가중치1
        // u값은 출발점 vertex1
        // v값도 출발점 vertex2
        // w값은 weight
        
        //****실수 할 수 있음 *****
        // 벡터에 넣는 순서([u]->[v]->[w])
        // [v]->[u]->[w]
        
        cin >> u >> v;
        a[u].push_back(make_pair(v,w));
        a[v].push_back(make_pair(u,w));
    }
}
