//
//  듣보잡 1764.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 02/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    int n,m;
    cin >> n >> m;
    set<string> g1;
    set<string> g2;
    vector<string> v;
    

    for(int i=0; i<n; i++){
        string str1;
        cin >> str1;
        g1.insert(str1);

    }
    
    for(int i=0; i<m; i++){
        string str2;
        cin >> str2;
        g2.insert(str2);
        
    }
    
    auto it1 = g1.begin();
    auto it2 = g2.begin();

    
    for(auto it1 = g1.begin(); it1 != g1.end(); it1++){
        for(auto it2 =g2.begin(); it2 != g2.end(); it2++){
            if(*it1 == *it2){
                v.push_back(*it1);
                break;
            }
        }
    }
    
    cout << v.size();
    sort(v.begin(),v.end());
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }

    
    
    
    
    return 0;
}
