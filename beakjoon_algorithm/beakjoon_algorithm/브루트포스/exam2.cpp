//
//  exam2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){


vector<int> v;

int value = 0;

do {
    
    
    cin >> value;
    v.push_back(value);
    
} while (getc(stdin) == ' ');
int n;
cin >> n;
vector<string> result;
    
sort(v.begin(),v.end());
    do{
        string ans;
        for(int i=0; i<v.size(); i++){
            ans += to_string(v[i]);
        }
//        cout << ans << '\n';
//        int num = stoi(ans);
        result.push_back(ans);
        
    }while(next_permutation(v.begin(),v.end()));
    
    
    sort(result.begin(),result.end());
    cout << result[n-1] << '\n';
    
//    for(int i=0; i<v.size(); i++){
//        cout << v[i];
//    }
    
    
    
    
    return 0;
}
