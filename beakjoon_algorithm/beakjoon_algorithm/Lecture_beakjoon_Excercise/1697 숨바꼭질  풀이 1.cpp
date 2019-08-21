//
//  1697 숨바꼭질.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int dist[200001];
int check[200001];
int m,n;
queue<int> q;
int cnt = 0;

void bfs(int x){
    dist[x] = 0;
    q.push(x);
    check[x] = 1;
    
    while(!q.empty()){
        int dx = q.front();
        q.pop();
        if(dx-1 >= 0){
            if(check[dx-1] == 0){
                check[dx-1] = 1;
                dist[dx-1] = dist[dx] + 1;
                q.push(dx-1);
            }
            
        }
        if(dx+1 < 200000){
            if(check[dx+1] == 0){
                check[dx+1] = 1;
                dist[dx+1] = dist[dx] + 1;
                q.push(dx+1);
            }
        }
        if(dx*2 < 200000){
            if(check[dx*2] == 0){
                check[dx*2] = 1;
                dist[dx*2] = dist[dx] + 1;
                q.push(dx*2);
            }
        }
    }
}
int main(void){
    
    cin >> m >> n;
    bfs(m);
    cout << dist[n] << '\n';
    return 0;
}

