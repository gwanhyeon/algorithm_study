//
//  14391종이조각.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 15/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int map[4][4];


int main(void){
    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    int ans = 0;
    // 0: -, 1: |
    // 가로에 대해서
    for(int s=0; s<(1<<(n*m)); s++){
        int sum = 0;
        for(int i=0; i<n; i++){
            int cur =0;
            for(int j=0; j<m; j++){
                int k = i * m + j;
                cout << k;
                if((s&(1<<k)) == 0){
                    cur = cur * 10 + map[i][j];
                }else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        
        
        // 세로에 대해서
        for(int j=0; j<m; j++){
            int cur = 0;
            for(int i=0; i<n; i++){
                int k = i*m + j;
                if((s&(1<<k)) != 0){
                    cur = cur * 10 + map[i][j];
                }else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ans = max(ans,sum);
        
    }
    cout << ans << '\n';
    return 0;
}
