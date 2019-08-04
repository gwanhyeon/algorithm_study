//
//  vertor_exam.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int main(void){
    // 벡터형태의 배열로 나타낼 수 있음.
    vector<int> map[100];

    map[0].push_back(1);
    map[0].push_back(2);
    map[0].push_back(3);
    
    // 예를 들어서 map[0]에 담긴 벡터 값들은 (1,2,3)이라고 생각하면
    // map[0].size()에 들어가있는 벡터값들을 i값으로 처리한후
    // 반복문 형태로 1 -> 2 -> 3의 값으로 접근하여 출력하는것을 알 수 있다.
    for (int i=0; i<map[0].size(); i++) {
        cout << map[0][i];
    }
    return 0;
}
