//
//  Level1-자연수 뒤집어 배열로 만들기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n = 12345;
    vector<int> answer;
    while(n > 0){
        answer.push_back(n%10);
        n /= 10;
    }
    for(int i=0; i<answer.size(); i++){
        cout << answer[i];
    }
    return 0;
}
