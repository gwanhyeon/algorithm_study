/*
 단지번호붙이기
 시간 제한    메모리 제한    제출    정답    맞은 사람    정답 비율
 1 초    128 MB    19045    7136    5006    38.328%
 문제
 <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
 
 
 
 입력
 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.
 
 출력
 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
 
 예제 입력 1
 7
 0110100
 0110101
 1110101
 0000111
 0100000
 0111110
 0111000
 예제 출력 1
 3
 7
 8
 9
 
*/

//
//  2667(단지번호붙이기).cpp
//  Algorigm_Study
//
//  Created by kgh on 2018. 8. 3..
//  Copyright © 2018년 kgh. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;


int map[25][25];    //25 x 25 max square Size Number

int size[323];     // 집 사이즈
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};    //동서남북
int cnt;    //단지의 개수
int n;  //입력받을 n

// 촏차
bool Check_Range(int a, int b){
    return (a>=0 && a<n) && (b>=0 && b<n);
}

//재귀를 통한 깊이 우선 탐색(dfs)
void dfs(int a, int b, int next_cnt){
    map[a][b] = next_cnt;
    
    for(int i=0; i<4; i++){
        int dy = a + dir[i][0];
        int dx = b + dir[i][1];
        
        if(Check_Range(dy, dx) && map[dy][dx] == 1){
            dfs(dy, dx, next_cnt);
        }
    }
}

int main(void){
    
    // input
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    // map 1일 경우
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            if (map[i][j] == 1) {   //dfs로 보낸다
                cnt++;
                dfs(i, j, cnt + 1);     // cnt+1해주는이유는 1증가한 다음단지번호를 붙이기위해서
            }
        }
    }
    // 0,1을 넘어가는경우
    for(int i=0; i<n; i++){ //dfs에서 key값을 통해서 각 dfs마다 숫자를 지정해 놓았습니다
        for(int j=0; j<n; j++){
            if(map[i][j] >1){   //같은 숫자의 갯수를 더해서 배열에 집어 넣습니다
                size[map[i][j] - 2]++;
            }
        }
    }
    
    sort(size, size + cnt); //정렬(오름차순으로)
    
    //출력
    cout << cnt << endl;
    for(int i=0; i<cnt; i++){
        cout << size[i] << endl;
    }
    
    return 0;
}

/*
#include <stdio.h>
#include <iostream>
using namespace std;

int sq[25][25];
int check[25];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};    //상하좌우 확인을 위한 2차원 배열
int cnt;
int dfs(int num){
    
    
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            
        }
        
    }
    
    
    return 0;
}
//좌표가 배열의 범위를 넘지 않는지
bool isInside(int a, int b){
    return (a>=0 && a<n) && (b>=0 && b<n);
}

//재귀를 통한 깊이 우선 탐색(dfs)
void dfs(int a, int b, int key){
    map[a][b] = key;
    
    for(int i=0; i<4; i++){
        int dy = a + dir[i][0];
        int dx = b + dir[i][1];
        
        if(isInside(dy, dx) && map[dy][dx] == 1){
            dfs(dy, dx, key);
        }
    }
}


출처: http://blockdmask.tistory.com/175 [개발자 지망생]
int main(void){
    int num;
    int sq_size;
    // 정사각형 크기 입력(Row,Column값 같음)

    cin >> sq_size;
  

    // 번호 입력
    
    for(int i=0; i<sq_size; i++){
        for(int j=0; j<sq_size; j++){
            scanf("%1d ",&num);
            sq[i][j] = num;
        }
    }
    
    // 출력
    
    for(int i=0; i<sq_size; i++){
        for(int j=0; j<sq_size; j++){
            cout << sq[i][j];
        }
    }
    
    // dfs call
    
    
    
    
    return 0;
}
 
 */
