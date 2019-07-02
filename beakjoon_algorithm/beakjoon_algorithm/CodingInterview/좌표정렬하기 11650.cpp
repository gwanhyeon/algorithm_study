//
//  좌표정렬하기 11650.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 02/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0; i<v.size(); i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << ' ' << v[i].second << "\n";
    
    }
    return 0;
}
