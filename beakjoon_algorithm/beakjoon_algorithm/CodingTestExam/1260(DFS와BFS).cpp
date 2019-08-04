/*
 문제
 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.
 
 입력
 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 한 간선이 여러 번 주어질 수도 있는데, 간선이 하나만 있는 것으로 생각하면 된다. 입력으로 주어지는 간선은 양방향이다.
 
 출력
 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
 
 예제 입력 1
 4 5 1
 1 2
 1 3
 1 4
 2 4
 3 4
 예제 출력 1
 1 2 4 3
 1 2 3 4
 
 Solution :
 <Stack>
 1. 스택의 top에 있는 정점을 기준으로 간선이 연결되어있고 아직 방문하지 않은 정점을 찾는다.
 
 2. 조건에 맞는 정점을 찾는다면 해당 정점을 스택에 넣은 후 break를 건다.
 
 3. 연결된 간선이 없고, 방문하지 않은 정점을 찾지 못한다면 pop.
 
 
 <Recursive>
 
 Stack 대신 보통 Recursive를 사용하여 구현하는경우가 많다.
 
*/


//
//  1260(DFS와BFS).cpp
//  Algorigm_Study
//
//  Created by kgh on 2018. 8. 3..
//  Copyright © 2018년 kgh. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

int n;                      // 정점의 개수
int check[1001];            // 방문 체크
int map[1001][1001];        // 맵 체크(인접행렬)

// 방문정점
void dfs(int x){
    
    check[x] = true;
    cout << check[x];
    
    //인접 리스트
    for(int i=0; i<a[x].size(); i++){
        int y = arr[x][i];
        
        if(check[i] == 0){
            dfs(i);
        }
    }

}
// dfs 구현하기
void dfs(int v_num)           // num 탐색할 정점의 번호
{
    printf("%d ",v_num);
    //cout << v_num;
    
    // 정점의 개수까지 반복문
    for (int i = 1; i <= n; i++)    {
        // 간선상태 확인(갈수있는경우) && 방문하지 않은경우
        if (map[v_num][i] && check[i] == 0) {
            check[i] = 1;           // 방문 체크
            dfs(i);
        }
    }
}

void bfs(int v_num)
{
    queue<int> q;
    
    // bfs 방문한곳 초기화
    for (int i = 0; i <= n; i++){
        check[i] = 0;
    }
    
    //시작정점 queue push
    q.push(v_num);
    // 정점 1로 check
    check[v_num] = 1;
    
    // queue 비어있지않을때 동안 계속해서 반복문을 돌려준다.
    while (!q.empty()) {
        
        int num = q.front();        // queue맨앞에 있는값 num저장
        q.pop();                    // queue에서 빼내준다.
        printf("%d ",num);
        
        // 모든 연결된 정점에대해서
        for (int i = 1; i <= n; i++) {
            // 갈수 있는 정점이고, 아직 체크되어있지 않은경우
            if (map[v_num][i] && check[i] == 0) {
                check[i] = 1;
                q.push(i);
            }
        }
    }
    printf("\n");
}

int main()
{
    int e, v;       // e=간선의 개수, v=탐색을 시작 할 정점의 번호
    int x,y;  // 정점 입력
    scanf("%d %d %d",&n,&e,&v);
    //cin >> n >> e >> v;     // 정점의 개수 , 간선의 개수, 탐색할 정점의 번호

    // 모든 간선 1로 초기화 시키기
    for (int i = 0; i < e; i++) {
        scanf("%d %d",&x,&y);
        //cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }
    
    //시작하는 정점을 1로 초기화 시켜주기. 시작점 체크
    check[v] = 1;
    
    // dfs call
    dfs(v);
    printf("\n");
    //bfs call
    bfs(v);
    
    return 0;
}



/*
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int map[1000][1000];
bool checkdfs[1000];
int n,m = 0;    // N 정점의 개수 , M 간선의 개수
int v = 0;      // v= 정점

stack<int> s;


void dfs(){
    
    
    
    for(int i=0; i<m; i++){
        
        for(int j=0; j<m; j++){
            
            if(map[i][j] != 1 && check[i] == 0){
                
                dfs();
            }
            
            if(map[i][j] == 1){
                cout << map[i][j];
            }
        }
   
    }
}
void init(){
    
    // N 정점의 개수, M 간선의 개수, V 정점
    cin >> n >> m >> v;
//    cout << "n = " << n;
//    cout << "m = " << m;
//    cout << "v = " << v;
    // 맵 초기화
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            map[i][j] = 0;
        }
    }
    
    check[v] = 1;           // 1은 방문했다고 체크하기 맨처음 초기화
    
    //입력한 값들 map에 간선 연결하기
    
    for(int i=0; i<m; i++){
        int x,y;
        
        cin >> x >> y;
        
        map[x][y] = 1;
        map[y][x] = 1;
        
    }
    
}
int main(void){
    init();
    dfs();

    return 0;
    
}
 
 */

