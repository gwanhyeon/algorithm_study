//
//  카카오 비밀지도.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 31/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> ans(n);
    for(int i=0; i<n; i++){
        arr1[i] |= arr2[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr1[i] % 2 == 1){
                ans[i] += "#";
            }else if(arr1[i] % 2 == 0){
                ans[i] += " ";
            }

            arr1[i] >>= 1;
        }
        reverse(ans[i].begin(), ans[i].end());
    }
    
    return ans;
}
