// https://programmers.co.kr/learn/courses/30/lessons/1832

#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int r[501][501];
int b[501][501];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int MOD = 20170805;
    memset(r,0,sizeof(r));
    memset(b,0,sizeof(b));
    
    r[1][1] = 1;
    b[1][1] = 1;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(city_map[i-1][j-1] == 0){
                r[i][j] = (r[i][j] + r[i][j-1] + b[i-1][j]) % MOD;
                b[i][j] = (b[i][j] + r[i][j-1] + b[i-1][j]) % MOD;
            }else if(city_map[i-1][j-1] == 1){
                r[i][j] = 0;
                b[i][j] = 0;
            }else {
                r[i][j] = r[i][j-1];
                b[i][j] = b[i-1][j];
            }
        }
    }
    answer = (r[m][n-1] + b[m-1][n]) % MOD;
    return answer;
}
