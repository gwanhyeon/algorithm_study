/*
 문제
 N×M크기의 배열로 표현되는 미로가 있다.
 
 1    0    1    1    1    1
 1    0    1    0    1    0
 1    0    1    0    1    1
 1    1    1    0    1    1
 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
 
 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
 
 입력
 첫째 줄에 두 정수 N, M(2≤N, M≤100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.
 
 출력
 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
 
 예제 입력 1
 4 6
 101111
 101010
 101011
 111011
 예제 출력 1
 15
 예제 입력 2
 4 6
 110110
 110110
 111111
 111101
 예제 출력 2
 9
 
 
 풀이 과정
 
 
 1. 탐색을 하면서 지나간 길을 등록하는 2차원 배열이 필요합니다.
 2. 지나간 길을 알릴 뿐만 아니라 몇번째에 왔는지 숫자를 기록하면서 이동
 3. queue를 이용하여 BFS 알고리즘으로 구현합니다.(STL Pair Container)
 -> 2차원 배열이므로 up, down, left, right를 갈때
 
 1) 해당 점이 map 내부에 있는지
 
 2) 해당 점이 지나온길이 아닌지
 
 3) 해당 점이 1 인지 (가는 길인지)
 

*/
//
//  2178.cpp
//  Algorigm_Study
//
//  Created by kgh on 2018. 7. 28..
//  Copyright © 2018년 kgh. All rights reserved.
//
#include <queue>
#include <stdio.h>
#include <iostream>
#include <utility>
using namespace std;
int r; // row
int c; // column
bool map[100][100];         // Map Max Size = 100 , Mini Size = 100
int check[100][100];        // Check Map Size Max = 100, Mini Size = 100
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};     // Left , Right , Down ,Up


void Init(){

cin >> r >> c;  // Row , Column Input
    
// Map 경로 설정
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int point;
            scanf("%1d", &point);
            // 입력값이 1일경우 가능한 경로( 나머지 가능하지 않은 경로 0은 자동으로 들어감)
            if(point==1){
                map[i][j] = true;
                //printf("%b",map[i][j]);
            }
        }
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%d",map[i][j]);
        }
        cout << endl;
        
    }
}
// Map 범위내에 있는지 확인하기
bool CheckMap(int a, int b){
    return (a >= 0 && a < r) && (b >=0 && b < c);
}

// bfs 구현 (1. 해당점 map내부에 위치해 있는지 확인 2. 지나온길인지 확인 3. Queue 자료 구조중 pair클래스 이용)
int Bfs_Logic(){
    int cur_r = 0;
    int cur_c = 0;            // [0][0] 인덱스 초기화
    
    queue<pair<int,int>> q;               // STL Queue 선언 및 pair을 쓰는 이유는 r,c값을 하나의 큐에 넣기위해서
    q.push(pair<int,int>(cur_r,cur_c));   // 첫번째 [0][0] 인덱스 Queue Push
    check[cur_r][cur_c] = 1;        // BFS 접근시 몇번째 점인지 체크
    
    // Queue가 비어있지 않을 경우
    while(!q.empty()){
        cur_r = q.front().first;            // 가장 맨앞에 있는값 r
        cur_c = q.front().second;           // 가장 맨앞에 있는값 c
        q.pop();        // 가장 최상단의 노드 값 queue
        
        // 시작점과 마지막 도착점에 도달하였을 경우 종료(시작점과 출발지점을 포함한다)
        if(cur_r == r && cur_c == c){
            break;
        }
        
        // Left Right Down Up
        for(int i=0; i<4; i++){
            
            // 방향 이동
            int next_r = cur_r + dir[i][0];
            int next_c = cur_c + dir[i][1];
            
            //next y, x가 배열 내부에 있고, check 2차원배열에 기록된적 없고, map에 true로 되어있으면
            if(CheckMap(next_r, next_c) && check[next_r][next_c] ==0 && map[next_r][next_c]){
                check[next_r][next_c] = check[cur_r][cur_c] + 1;            //Check Map 포인트에 표시
                q.push(pair<int,int>(next_r,next_c));                       // 그리고 움직인 좌표값을 다시 큐에다가 push해준다. BSF특징중 하나인 연결된 간선을 처리하기위해서
                
            }
        }
    }
    return check[r-1][c-1];
}
int main(void){
    
    int result = 0;         //Final Result Variable
    Init();                 // Map Init Function call
    result = Bfs_Logic();   // Bfs Logic Function call
    cout << result <<endl;  // Result
    return 0;
    
}
        
        
        
    


