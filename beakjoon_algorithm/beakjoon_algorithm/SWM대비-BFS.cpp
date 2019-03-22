//
//  SWM대비-BFS.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//


// 1. 큐에서 하나의 노드를 꺼냅니다.
// 2. 해당 노드에 연결된 노드 중 방문하지 않은 노드를 방문하고, 차례대로 큐에 삽입합니다.
#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int number = 7;
int c[7];
vector<int> a[8];

//vector<int> arr(5,0) 이렇게 쓰면 5개짜리 배열을 생성하고 초기값으로 0을 넣는다는 뜻입니다.
void bfs(int start){
    
    queue<int> q; // 1. 큐 선언
    q.push(start); // 2. 시작점을 큐에 넣어준다
    c[start] = true; // 3. c배열에 방문 체크를 한다.
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x;
        
        for(int i=0; i<a[x].size(); i++){
            int y =a[x][i];
            if(!c[y]){
                q.push(y);
                c[y] = true;
            }
        }
    }
    
}

int main(void){
    a[1].push_back(2);
    a[2].push_back(1);
    // 1과 3를 연결합니다.
    a[1].push_back(3);
    a[3].push_back(1);
    // 2과 3를 연결합니다.
    a[2].push_back(3);
    a[3].push_back(2);
    // 2과 4을 연결합니다.
    a[2].push_back(4);
    a[4].push_back(2);
    // 2과 5를 연결합니다.
    a[2].push_back(5);
    a[5].push_back(2);
    // 3와 6를 연결합니다.
    a[3].push_back(6);
    a[6].push_back(3);
    // 3와 7을 연결합니다.
    a[3].push_back(7);
    a[7].push_back(3);
    // 4와 5를 연결합니다.
    a[4].push_back(5);
    a[5].push_back(4);
    // 6과 7을 연결합니다.
    a[6].push_back(7);
    a[7].push_back(6);
    // BFS를 수행합니다.
    bfs(1);
    return 0;
    
    
    return 0;
}

