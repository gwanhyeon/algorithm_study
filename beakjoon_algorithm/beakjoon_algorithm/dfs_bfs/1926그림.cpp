#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int Maze[501][501];
bool check[501][501];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;      // column, row
    // map initialize
    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            cin >> Maze[i][j];
        }
    }
    int num_cnt = 0;        // 그림의 개수(하나의 영역)
    int num_max = 0;        // 최대값
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(Maze[i][j] == 0 || check[i][j]){
                continue;
            }
            int area = 0;           // 1칸에 해당하는 넓이(그림에서의 넓이)
            // Picture counting num_cnt++;
            num_cnt++;
            queue<pair<int,int>> q;
            Maze[i][j] = 1;
            check[i][j] = true;
            q.push({i,j});
            // while loop 안쪽에서는 해당 그림의 넓이를 구해준다.
            while(!q.empty()){
                area++;     // 그림의 넓이 추가(1)
                auto cur= q.front();
                q.pop();
                
                for(int z=0; z<4; z++){
                    int dx = cur.first + dir[z][0];
                    int dy = cur.second + dir[z][1];
                    
                    if(dx < 0 || dx >= n || dy < 0 || dy >= m){
                        continue;
                    }
                    if(check[dx][dy] || Maze[dx][dy] != 1){
                        continue;
                    }
                    check[dx][dy] = 1;
                    q.push({dx,dy});
                    
                }
            }
            num_max = max(num_max,area);
        }
    }
    
    cout << num_cnt << '\n' << num_max;
    
    
    return 0;
}
