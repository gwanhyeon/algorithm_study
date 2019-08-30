//
//  9019 DSLR.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 24/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10000;
int t;
int check[MAX+1];
char how[MAX+1];
int dist[MAX+1];
int from[MAX+1];

void bfs(int x,int y){
    queue<int> q;
    
    check[x] = 1;
    dist[x] = 0;
    from[x] = -1;
    q.push(x);
    
    while(!q.empty()){
        int dx = q.front();
        q.pop();
        
        // D
        int next = (dx*2) % 10000;
        if(check[next] == 0){
            q.push(next);
            check[next] = 1;
            dist[next] = dist[dx]+1;
            from[next] = dx;
            how[next] = 'D';
        }
        
        // S
        next = dx-1;
        if(next == -1){
            next = 9999;
        }
        if(check[next] == 0){
            q.push(next);
            check[next] =1;
            dist[next] = dist[dx] + 1;
            from[next] = dx;
            how[next] = 'S';
        };
        // L
        next = (dx%1000)*10 + dx/1000;
        if(check[next] == 0){
            q.push(next);
            check[next] = 1;
            dist[next] = dist[dx] + 1;
            from[next] = dx;
            how[next] = 'L';
        }
        // R
        next = (dx/10) + (dx%10)*1000;
        if(check[next] == 0){
            q.push(next);
            check[next]=1;
            dist[next] = dist[dx] + 1;
            from[next] = dx;
            how[next] = 'R';
        }
    }
    
}


int main(void){
    cin >> t;
    
    while(t--){
        int x,y;
        cin >> x >> y;
        memset(check,0,sizeof(check));
        memset(how,0,sizeof(how));
        memset(dist,0,sizeof(dist));
        memset(from,0,sizeof(from));
        
        bfs(x,y);
        string ans = "";
        while (x != y) {
            ans += how[y];
            y = from[y];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    return 0;
}

