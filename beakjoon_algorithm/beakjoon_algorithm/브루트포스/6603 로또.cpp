//
//  6603 로또.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

// N개의 수중 k개를 뽑는경우 중복 조합
// true ,false를 처리 할 수 있어야함


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    while(true){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            
            cin >> v[i];
            if(v[0] == 0){
                return 0;
            }
        }
        sort(v.begin(), v.end());
        vector<int> check(n);
        // 6개 아닌경우
        for(int i=0; i<n-6; i++){
            check.push_back(0);
        }
        //6개 까지
        for(int i=0; i<n; i++){
            check.push_back(1);
        }
        vector<vector<int>> ans(n);
        do{
            vector<int> s;
            for(int i=0; i<v.size(); i++){
                if(check[i] == 1){
                    s.push_back(v[i]);
                }
            }
            ans.push_back(s);
        }while(next_permutation(v.begin(), v.end()));
        sort(ans.begin(),ans.end());
        
        for(auto &ele : ans){
            for(int i=0; i<n; i++){
                cout << ele[i] << ' ';
            }
            cout << '\n';
        }
        cout <<'\n';
    }
    
    
    
    return 0;
}
