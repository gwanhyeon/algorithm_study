//
//  Level1-평균구하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for(int i=0; i<arr.size(); i++){
        answer += arr[i];
    }
    answer = answer / arr.size();
    return answer;
}
