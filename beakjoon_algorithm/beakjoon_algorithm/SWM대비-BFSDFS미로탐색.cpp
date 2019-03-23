#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int r;
int c;
bool map[101][101];
int check[101][101];
// 동서남북
int dir[4][2]= {{-1,0},{1,0},{0,1},{0,-1}};

int checkmap(int a,int b){
    return (a >= 0 && a < r) && (b >= 0 && b < c);
    
}

int bfs(int cur_r,int cur_c){
    queue<pair<int,int>> q;
    q.push(pair<int,int>(cur_c,cur_r));
    check[cur_r][cur_c] = 1;
    
    while(!q.empty()){
        cur_r = q.front().first;
        cur_c = q.front().second;
        q.pop();
        
        if(cur_r == r && cur_c == c){
            break;
        }
    
        for(int i=0; i<4; i++){
            int next_r = cur_r + dir[i][0];
            int next_c = cur_c + dir[i][1];
            if(checkmap(next_r,next_c) && check[next_r][next_c] ==0 && map[next_r][next_c]){
                
                check[next_r][next_c] = check[cur_r][cur_c] + 1;
                q.push(pair<int,int>(next_r,next_c));
                
            }
        }
    }
    return check[r-1][c-1];
}

int main(void){
    cin >> r >> c;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int point;
            scanf("%1d",&point);
            
            if(point == 1){
                map[i][j] = true;
            }
        }
    }
    int result = bfs(0,0);
    
    cout << result;

    return 0;
}
