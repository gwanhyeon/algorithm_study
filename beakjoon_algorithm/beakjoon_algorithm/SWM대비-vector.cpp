//
//  SWM대비-vector.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void vector_test(vector<vector<int>> a){
    
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a[i].size(); j++){
            cout << a[i][j] << endl;
        }
    }
}

int main(void){
    vector<int> V;      // 1차원 벡터
    vector<int> V2(5);       // 1차원 배열 5개 할당과 같은말
    vector<vector<int>> V3; // 2차원 배열 arr[][]
    vector<vector<int>> V4(5); // 2차원 배열 arr[5][];
    vector<vector<int>> V5(5,vector<int>(3,0)); // arr[5][3] 모든값 0으로 할당
    
    vector_test(V5);
 
    
    
    
    
    
}
