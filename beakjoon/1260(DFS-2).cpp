//
//  1260(DFS-2).cpp
//  Algorigm_Study
//
//  Created by kgh on 2018. 8. 6..
//  Copyright © 2018년 kgh. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

int n;
int visit[1001];
int graph[1001][1001];

// dfs call
void dfs(int num)
{
    printf("%d ", num);     // 값 출력
    for (int i = 1; i <= n; i++)    {
        // graph 갈수있고, 방문하지 않은경우
        if (graph[num][i] && visit[i] == 0) {
            visit[i] = 1;
            dfs(i);            // recursive call
        }
    }
}
//bfs call
void bfs(int start)
{
    // queue
    queue<int> que;
    // init
    for (int i = 0; i <= n; i++){
        visit[i] = 0;
    }
    que.push(start);
    visit[start] = 1;        // visited point check
    
    // queue check roof
    while (!que.empty()) {
        int num = que.front();
        que.pop();
        
        printf("%d ", num);        // 값 출력
        
        // 모든 점 체크
        for (int i = 1; i <= n; i++) {
            // 연결선 체크 및 방문하지 않았을경우
            if (graph[num][i] && visit[i] == 0) {
                visit[i] = 1;       //visited point check
                que.push(i);        //queue push
            }
        }
    }
    printf("\n");
}

int main()
{
    int m, start;
    int x, y;
    
    // input
    scanf("%d %d %d", &n, &m, &start);
    
    // init
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    visit[start] = 1;
    dfs(start);        //dfs call
    printf("\n");
    bfs(start);        // bfs call
    
    return 0;
}
