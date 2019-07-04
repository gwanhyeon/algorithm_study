//
//  배열복원하기16967.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 02/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int A[3][301];
int B[3][301];

int main(void){
    int h,w,x,y;
    cin >> h >> w >> x >> y;
    
    // B입력 완료
    for(int i=0; i<h+x; i++){
        for(int j=0; j<w+y; j++){
            cin >> B[i][j];
        }
    }
    // A이동
    for(int i=0; i<h+x; i++){
        for(int j=0; j<w+y; j++){
            // A이동 범위 체크
            if(B[i][j] == 0){
                continue;
            }
            // 이동한 A체크
            if(i+1 <= h+x && j+1 <= w+y){
                A[i+1-x][j+1-y] = B[i][j];
            // 기존의 A체크 하나존재
            }else if(i < h+x && j < w+y){
                A[i+1-x][j+1-y] = B[i][j];
            }else if((i+1<h+x && j+1 < w+y) && (i < h+x && j <w+y)){         // 둘다 포함
                A[i][j] = B[i][j]-A[i-x][j-y];
            }
            else{  // 범위 벗어난 경우
                A[i][j] = B[i][j];
            }
        }
    }
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
