//
//  1987 알파벳.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// * 문자 배열 입력받기 ** 중요함..
int dir[4][2] ={{-1,0},{1,0},{0,-1},{0,1}};
int r,c;

int go(vector<string> &board, vector<bool> &check,int x,int y){
    int ans = 0;

    for(int i=0; i<4; i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()){
            if(check[board[nx][ny]-'A'] == false){
                check[board[nx][ny]-'A'] = true;
                
                int next = go(board,check,nx,ny);
                if(ans < next){
                    ans = next;
                }
                check[board[nx][ny]-'A'] = false;
            }
        
        }
        
    }
    return ans+1;
}

int main(void){
    
    cin >> r >> c;
    vector<string> board(r);
    vector<bool> check(26); // 알파벳 개수가 26개(대문자)
    
    for(int i=0; i<r; i++){
            cin >> board[i];
    }
  
    check[board[0][0] -'A'] = true; // 맨처음 말을 시작점으로 바꾸기 위해 true로 변경한다.
    // 대문자를 정수형처럼 체크하기 위해서 
    cout << go(board,check,0,0) << '\n';
    
    
    return 0;
}

/* 내 풀이와 차이점 */
/*
 2 4
 CAAB
 ADCB#include <iostream>
#include <string>
using namespace std;
// * 문자 배열 입력받기 ** 중요함..
char map[20][20];
bool check[400];
int dir[4][2] ={{-1,0},{1,0},{0,1},{-1,0}};
int r,c;

int go(int x,int y){
    
    if(x == r && y == c){
        return 1;
    }
    int sum = 0;
    for(int i=0; i<4; i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx >= 0 && ny < sizeof(map) / sizeof(char) && ny >= 0 && ny < sizeof(map) / sizeof(char)){
            if(check[map[nx][ny]-'A'] == false){
                check[map[nx][ny]-'A'] = true;
                sum += go(nx,ny);
                check[map[nx][ny]-'A'] = false;
            }
//            if(map[x][y] != map[x+i][y+i]){
//                check[map[x+i][y+i]] = true;
//                sum += go(x+1, y+1);
//                check[map[x+i][y+i]] = false;
//            }
//
        }
        
    }
    return sum;
}

int main(void){
 
    cin >> r >> c;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            
            cin >> map[i][j];
        }
    }
    int sum = go(1,1);
    cout << sum;
    
    return 0;
}
*/
