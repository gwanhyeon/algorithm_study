
//
//  프로그래머스_TOP.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 29/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;      // 정답을 저장시킬놈
    
    // 레이저 오른쪽 -> 왼쪽으로 주는 값을 체크해야하므로
    for(int i=heights.size(); i > 0; i--){
        // 해당 하는 레이저 i의값과 그 나머지 값들을 비교 해야함
        int index = i-1;
        int result = 0;
        for(int j=index; j>0; j--){
            if(heights[i] < heights[j] && result < heights[j]){
                result = heights[j];
                break;
            }
        }
        answer.push_back(result);
    }
    return answer;
}
