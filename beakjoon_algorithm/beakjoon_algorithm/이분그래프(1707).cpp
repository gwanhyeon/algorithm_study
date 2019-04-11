//
//  이분그래프(1707).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int num;
int n,m;
int u,v;
vector<int> map[20001];
int check[20001];

void dfs(int v,int c){
    check[v] = c;
    cout << "1=>";
    for(int i=0; i<map[v].size(); i++){
        int next = map[v][i];
        // false값이면, dfs를 재수행하여 2번째 집단에 방문을 하면서 여부 확인.
        if(check[next] == 0){
            dfs(next, 3-c);
        }
    }
}
int main(void){
    cin >> num;
    // 테스트 케이스
    while(num--){
        cin >> n>> m;
        // 이것은 bool값과 다르게 초깃값이 0으로 설정되어있는지 확인 할 수 없음
        // 이분탐색을 하기 위해서는 다른 부류
        // 0 = 탐색 X 1= 1집단 탐색 O , 2= 2집단 탐색 O
        // 따라서 모든 값들 초기화!
        for(int i=1; i<=n; i++){
            map[i].clear();         // vector를 초기화 시킬떄는 clear() 메소드를 사용한다
            check[i] = 0;           // check bool 초기화 시키기 위해서는 check[i]=0형식으로 사용한다.
            
        }
        // 그래프에 간선을 연결해준다 G=(v,e);
        for(int i=0; i<m; i++){
            // queue push_back
            cin >> u >> v;
            map[u].push_back(v);
            map[v].push_back(u);
            
        }
        // check[i] == 0 일경우는 아직 방문하지 않았던 경우이기때문에 dfs수행.
        for(int i=1; i<=n; i++){
            if(check[i] == 0){
                dfs(i,1);
            }
        }
        // 같은 집단에 있는 값들이
        bool tf = true;
        for(int i=1; i<=n; i++){
            for(int k=0; k<map[i].size(); k++){
                int j = map[i][k];
                // 1 / 2 집단에서의 값이 같다는것은
                // 결국엔 같은 집단끼리 이어진 값이 있다는것 ! 중요함!
                if(check[i] == check[j]){
                    tf = false;
                }
            }
        }
        
        cout << (tf ? "YES" : "NO") <<"\n";
    }
    return 0;
}
