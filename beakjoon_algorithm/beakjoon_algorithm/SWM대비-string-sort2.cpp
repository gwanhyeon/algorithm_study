//
//  SWM대비-string-sort2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
#include <iostream>

using namespace std;

int n, m;
int a[10001];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &m);
        a[m]++;
    }
    for (int i = 0; i < 10001; i++){
        while(a[i] != 0) {
            printf("%d\n", i);
            a[i]--;
        }
    }
}
