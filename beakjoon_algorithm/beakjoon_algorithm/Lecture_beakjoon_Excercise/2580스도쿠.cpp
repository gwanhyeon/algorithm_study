//
//  2580스도쿠.cpp
//  beakjoon_alrecursiverithm
//
//  Created by kgh on 12/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <iostream>
using namespace std;
int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n=9;
int square(int x, int y) {
    return (x/3)*3+(y/3);
    
}
bool recursive(int z) {
    if (z == 81) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = z/n;// 9*x+y 스도쿠를 1차원 배열로 나타냈을때 몇번째 행렬인지 찾을때
    int y = z%n;
    if (a[x][y] != 0) {
        return recursive(z+1);
    } else {
        for (int i=1; i<=9; i++) {
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i]==0) {
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
                a[x][y] = i; // 아직 들어가지 않은값중에 1-9값을 순회한 값중 빈값을 넣어준다.
                if (recursive(z+1)) {
                    return true;
                }
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
            }
        }
    }
    return false;
}
int main() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                c[i][a[i][j]] = true;
                c2[j][a[i][j]] = true;
                c3[square(i,j)][a[i][j]] = true;
            }
        }
    }
    recursive(0);
    return 0;
}
