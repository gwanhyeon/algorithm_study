//
//  1806 부분합.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 17/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    vector<int> v;
    vector<int> answer;
    int n,s;
    int sum = 0;
    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
        
    }
    int min = 999999;
    for(int i=1; i<n; i++){
        sum =0;
        for(int j=i; j<n; j++){
        
            if(sum < s){
                sum += v[j];
            }
            if(sum >= s){
                if(min > v[j]){
                    min = v[j];
                }
            }
        }
    }
    v.clear();
    if(sum == 0){
        cout << "0";
    }else {
        cout << min << '\n';
//        int result = *min_element(answer.begin(),answer.end());
//        cout << result << '\n';
    }
    return 0;
}
