//
//  풀이 6.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
int check[101][101];
int dist[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
using namespace std;
bool compare(pair<int,double> &a, pair<int,double> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main(void){
    
    
    
    return 0;
}
