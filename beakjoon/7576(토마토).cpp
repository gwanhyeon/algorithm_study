/*
 토마토
 시간 제한    메모리 제한    제출    정답    맞은 사람    정답 비율
 1 초    128 MB    30813    8424    5397    26.207%
 문제
 철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.
 

 창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
 
 토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
 
 
 
 
 \
 
 입력
 첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N 은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
 
 출력
 여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
 
 예제 입력 1
 6 4
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 0 0 1
 예제 출력 1
 8
 예제 입력 2
 6 4
 0 -1 0 0 0 0
 -1 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 0 0 1
 예제 출력 2
 -1
 예제 입력 3
 6 4
 1 -1 0 0 0 0
 0 -1 0 0 0 0
 0 0 0 0 -1 0
 0 0 0 0 -1 1
 예제 출력 3
 6
 예제 입력 4
 5 5
 -1 1 0 0 0
 0 -1 -1 -1 0
 0 -1 -1 -1 0
 0 -1 -1 -1 0
 0 0 0 0 0
 예제 출력 4
 14
 예제 입력 5
 2 2
 1 -1
 -1 1
 예제 출력 5
 0
 */
//
//  7576.cpp
//  Algorigm_Study
//
//  Created by kgh on 2018. 7. 29..
//  Copyright © 2018년 kgh. All rights reserved.
//


#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

int box[1001][1001];            // 박스 범위 1000
int check[1001][1001];          // 체크 범위 1000
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};    // Left, Right, Down, Up

int main(){
    int r,c;
    
    // 큐 선언 int형식
    queue<pair<int,int>> q;
    // r, c 입력받기
    scanf("%d %d",&r,&c);
    
    // c줄부터 상자에 담긴 토마토 정보가 나오므로 column까지
    for(int i = 0;i<c;i++){
        // row 까지
        for(int j = 0;j<r;j++){
            check[i][j] = -1;           // Check부분 -1값 모두 넣어 초기화
            scanf("%d",&box[i][j]);     // 박스에 들어갈 값 입력
            
            // 박스에 익혀진 지점 체크
            if(box[i][j] > 0){
                check[i][j] = 0;            // 익혀진곳 체크
                q.push(make_pair(i,j));     // queue에 push
            }
        }
    }
    
    //int dx[4] = {1,0,-1,0};
    //int dy[4] = {0,1,0,-1};
    
    int next_r,next_c;          // 다음 위치
    
    // 큐가 비어있지 않는 경우
    while(!q.empty()){
        int cur_r = q.front().first;        // 좌표 r
        int cur_c = q.front().second;       // 좌표 c
    
        q.pop();                            // queue 맨앞에 있는것들 pop
        // Left,Right,Down,Up
        for(int i = 0;i<4;i++){
            next_r = cur_r+dir[i][0];       // 다음 r 좌표
            next_c = cur_c+dir[i][1];       // 다음 c 좌표
            
            // box가 비어있지 않고, check된곳이 없을 경우(-1일경우 -1전체 초기화 하였음)
            if(box[next_r][next_c] != -1  && check[next_r][next_c] == -1){
                q.push(make_pair(next_r,next_c));                           // 다음 좌표들 queue에 넣기(반복문으로 queue pop 시행하므로)
                check[next_r][next_c] = check[cur_r][cur_c] + 1;            // 토마토 다음날(+1) 익혀버리기
            }
        }
    }
    int result = 0 ;
    // column부터 출력된다고 했으므로,
    for(int i = 0;i<c;i++){
        // Row
        for(int j = 0;j<r;j++){
            // 덜익혀지고 , 비어있는부분 종료 시켜버리기
            if(box[i][j] == 0 && check[i][j] == -1){
                printf("-1"); return 0;
            }
            // 익혀진곳중 가장큰값을 가진곳이 토마토가 모두 익은날
            if(check[i][j] > result){
                result = check[i][j];
            }
        }
    }
    printf("%d\n",result);

}











/* 토마토 자꾸 틀리다고 나와서 새로 만들기 위한 백업용
 
 
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int check[1001][1001];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};        //Left , Right , Up, Down
int r,c;
int cnt =0;
void Init(){
    scanf("%d %d",&r,&c);
    //cin >> r >> c;          // 상자 r=가로,c=세로 Input the number
    
    // Box Setting
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int state;
            scanf("%d",&state);
            
            
            if(state == 1){             // Tomato 익었을 경우
                map[i][j] = 1;
            }else if(state == 0){       // Tomato 익지 않았을경우
                map[i][j] = 0;
            }else if(state == -1){      // Tomato 창고에 들어있지 않을경우
                map[i][j] = -1;
            }
        }
    }
    // Box print
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}
// Map 범위내에 있는지 확인하기
bool CheckMap(int a, int b){
    return (a >= 0 && a < r) && (b >=0 && b < c);
}
int Bfs_Check(){
    int cur_r,cur_c = 0;
    queue<pair<int,int>> q;
    q.push(pair<int,int>(cur_r,cur_c));
    int res = 0 ;
    check[cur_r][cur_c] = 1;        // 포인트 체크
    
    
    while(!q.empty()){
        cur_r = q.front().first;        // 첫번째 값 빼기
        cur_c = q.front().second;       // 두번째 값 빼기
        
        q.pop();            // Queue 첫번째 값 빼버리기

        // 4 Left Right Down Up of kind , for roof number of four
        for(int i=0; i<4; i++){
            
            // 방향 이동
            int next_r = cur_r + dir[i][0];
            int next_c = cur_c + dir[i][1];
            if(map[next_r][next_c] != -1 && check[next_r][next_c] == -1){
                q.push(pair<int,int>(next_r,next_c));
                check[next_r][next_c] = check[cur_r][cur_c]+1;
            }
        
        }
    }
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(map[i][j] == 0 && check[i][j] == -1) {
                printf("-1\n"); return 0;
                
            }
            if(check[i][j] > res){
                res = check[i][j];
            }
        }
    }
    return res;        // 100 사이즈만큼이므로 99까지 사이즈만큼 처리
    
}
int main(void){
    int result = 0;
    Init();         // Map Init Function Call
    result = Bfs_Check();
    cout << result;
    
    return 0;
    
}
 
 */

