/*
 문제
 n*n의 크기의 대나무 숲이 있다. 욕심쟁이 판다는 어떤 지역에서 대나무를 먹기 시작한다. 그리고 그 곳의 대나무를 다 먹어 치우면 상, 하, 좌, 우 중 한 곳으로 이동을 한다. 그리고 또 그곳에서 대나무를 먹는다. 그런데 단 조건이 있다. 이 판다는 매우 욕심이 많아서 대나무를 먹고 자리를 옮기면 그 옮긴 지역에 그 전 지역보다 대나무가 많이 있어야 한다. 만약에 그런 지점이 없으면 이 판다는 불만을 가지고 단식 투쟁을 하다가 죽게 된다(-_-)
 
 이 판다의 사육사는 이런 판다를 대나무 숲에 풀어 놓아야 하는데, 어떤 지점에 처음에 풀어 놓아야 하고, 어떤 곳으로 이동을 시켜야 둘 다 소중한 생명이지만 판다가 최대한 오래 살 수 있는지 고민에 빠져 있다. 우리의 임무는 이 사육사를 도와주는 것이다. n*n 크기의 대나무 숲이 주어져 있을 때, 이 판다가 최대한 오래 살려면 어떤 경로를 통하여 움직여야 하는지 구하여라.
 
 입력
 첫째 줄에 대나무 숲의 크기 n(1 ≤ n ≤ 500)이 주어진다. 그리고 둘째 줄부터 n+1번째 줄까지 대나무 숲의 정보가 주어진다. 대나무 숲의 정보는 공백을 사이로 두고 각 지역의 대나무의 양이 정수 값으로 주어진다. 대나무의 양은 1,000,000보다 작거나 같은 자연수이다.
 
 출력
 첫째 줄에는 판다가 최대한 살 수 있는 일수(K)를 출력한다.
 */
//
//  1937(욕심쟁이판다).cpp
//  Algorigm_Study
//
//  Created by kgh on 2018. 8. 13..
//  Copyright © 2018년 kgh. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int dp[501][501] = {0, };
int tree[501][501] = {0, };
int n;

// 범위 체크
bool isInner(int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < n) {
        return true;
    }
    return false;
}

// dfs
int dfs (int x, int y) {
    
    if (dp[x][y] == 1) {
        // 동서남북
        for (int idx = 0; idx < 4; ++idx) {
            int newX = x + dx[idx];
            int newY = y + dy[idx];
            // 안에있는지 체크한후
            if (isInner(newX, newY)) {
                // 대나무 개수가 더많은지 체크한후 dp저장
                if (tree[x][y] < tree[newX][newY]) {
                    dp[x][y] = max(dp[x][y], dfs(newX, newY) + 1);
                }
            }
        }
    }
    return dp[x][y];
}

int main()
{
    int result = -1;
    // 대숲 크기 입력
    cin >> n;
    
    // 대나무양 입력하기, dp 1로 초기화
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tree[i][j];
            dp[i][j] = 1;
        }
    }
    
    // 결과값 저장하기(판다가 최대한 살수 있는 일수)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // dfs결과에 따른 최대값 저장 result
            result = max(result, dfs(i, j));
        }
    }
    // 결과 출력
    cout << result << endl;
}



