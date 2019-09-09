//
//  14500 테트노미로.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <iostream>
using namespace std;
int a[500][500];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            // ㅡ ㅡ ㅡ ㅡ
            if (j+3 < m) {
                int result = a[i][j] + a[i][j+1] + a[i][j+2] + a[i][j+3];
                if (ans < result) ans = result;
            }
            // |
            // |
            // |
            // |
            
            if (i+3 < n) {
                int result = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j];
                if (ans < result) ans = result;
            }
            // |
            // ㅡ ㅡ ㅡ
            
            if (i+1 < n && j+2 < m) {
                int result = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
                if (ans < result) ans = result;
            }
            // ㅡ ㅡ
            // |
            // |
            if (i+2 < n && j+1 < m) {
                int result = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+2][j];
                if (ans < result) ans = result;
            }
            // ㅡ ㅡ ㅡ
            //      |
            if (i+1 < n && j+2 < m) {
                int result = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+2];
                if (ans < result) ans = result;
            }
            //   |
            //   |
            // ㅡ |
            if (i+2 < n && j-1 >= 0) {
                int result = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j-1];
                if (ans < result) ans = result;
            }
            //   |
            // ㅡ ㅡ ㅡ
            if (i-1 >= 0 && j+2 < m) {
                int result = a[i][j] + a[i][j+1] + a[i][j+2] + a[i-1][j+2];
                if (ans < result) ans = result;
            }
            // |
            // |
            // | ㅡ
            if (i+2 < n && j+1 < m) {
                int result = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j+1];
                if (ans < result) ans = result;
            }
            // ㅡ ㅡ ㅡ
            // |
            if (i+1 < n && j+2 < m) {
                int result = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j];
                if (ans < result) ans = result;
            }
            // ㅡ ㅡ
            //    |
            //    |
            if (i+2 < n && j+1 < m) {
                int result = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+2][j+1];
                if (ans < result) ans = result;
            }
            // | |
            // | |
            if (i+1 < n && j+1 < m) {
                int result = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
                if (ans < result) ans = result;
            }
            //    ㅡ ㅡ
            //  ㅡ ㅡ
            if (i-1 >= 0 && j+2 < m) {
                int result = a[i][j] + a[i][j+1] + a[i-1][j+1] + a[i-1][j+2];
                if (ans < result) ans = result;
            }
            // |
            // | |
            //   |
            if (i+2 < n && j+1 < m) {
                int result = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+2][j+1];
                if (ans < result) ans = result;
            }
            // ㅡ ㅡ
            //    ㅡ ㅡ
            if (i+1 < n && j+2 < m) {
                int result = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+1][j+2];
                if (ans < result) ans = result;
            }
            //     |
            //   | |
            //   |
            if (i+2 < n && j-1 >= 0) {
                int result = a[i][j] + a[i+1][j] + a[i+1][j-1] + a[i+2][j-1];
                if (ans < result) ans = result;
            }
            
            // ㅡ ㅡ ㅡ
            if (j+2 < m) {
                int result = a[i][j] + a[i][j+1] + a[i][j+2];
                //    |
                // ㅡ ㅡ ㅡ
                if (i-1 >= 0) {
                    
                    int result2 = result + a[i-1][j+1];
                    if (ans < result2) ans = result2;
                }
                
                // ㅡ ㅡ ㅡ
                //    |
                if (i+1 < n) {
                    int result2 = result + a[i+1][j+1];
                    if (ans < result2) ans = result2;
                }
            }
            // ㅡ ㅡ ㅡ
            if (i+2 < n) {
                int result = a[i][j] + a[i+1][j] + a[i+2][j];
                //    |
                //    | ㅡ
                //    |
                if (j+1 < m) {
                    int result2 = result + a[i+1][j+1];
                    if (ans < result2) ans = result2;
                }
                //   |
                // ㅡ |
                //   |
                if (j-1 >= 0) {
                    int result2 = result + a[i+1][j-1];
                    if (ans < result2) ans = result2;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
    
    
    
