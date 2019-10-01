//
//  n과 m(1).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 27/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void){
    int n,m;
    cin >> n >> m;
    
    vector<int> v(n);
    vector<int> check;
    for(int i=1; i<=n; i++){
        v[i-1] = i;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n-m; i++){
        check.push_back(0);
    }
    for(int i=0; i<n; i++){
        check.push_back(1);
    }
    
    vector<int> ans;
    
    do{
        vector<int> res;
        for(int i=0; i<n; i++){
            if(check[i] == 1){
                cout << v[i] << '\n';
            }
        }
    }while(next_permutation(v.begin(), v.end()));
return 0;
}
