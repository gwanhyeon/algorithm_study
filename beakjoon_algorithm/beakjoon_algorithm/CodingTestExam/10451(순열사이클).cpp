//
//  10451(순열사이클).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int map[1001];
bool check[1001];
void dfs(int v){
    // 체크된 값이면 종료
    if(check[v]){
        return;
    }
    // 체크되지 않은 값이면 종료 X
    check[v] =true;
    // 다시 dfs호출
    dfs(map[v]);
}
int main(void){
    
    // 테스트 케이스 입력
    int t;
    cin >> t;
    // 테스트 케이스 개수 만큼 While
    while(t--){
        // 순열의 개수 입력
        int n;
        cin >> n;
        
        // 맵 초기화 , check 값 초기화
        for(int i=1; i<=n; i++){
            cin >> map[i];           // map value input
            check[i] = false;        // map에 값 넣어주고 false 값
        }
        // 순열 사이클의 개수를 담기위한 ans
        int ans = 0;
        
        // 체크 되지 않았던 값일 경우 dfs(i)만큼 진행.
        // 연결된 값들을 확인하기 위함.
        for(int i=1; i<=n; i++){
            if(check[i] == false){
            dfs(i);
            ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
