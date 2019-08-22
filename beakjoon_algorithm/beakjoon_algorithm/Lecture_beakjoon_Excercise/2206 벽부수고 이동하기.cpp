//
//  벽부수고 이동하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
int map[1001][1001];
int check[1001][1001];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};


int n,m;
using namespace std;

int main(void){

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    
    bfs(0,0);
    
    return 0;
    
}

