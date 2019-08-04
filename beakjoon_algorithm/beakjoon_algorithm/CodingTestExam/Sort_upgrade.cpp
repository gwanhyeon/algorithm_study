
//
//  Sort_upgrade.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){
    int n;
    scanf("%d",&n);
    
    vector<pair<int,int>> a(n);
    // 백터의 배열수 만큼생성시켜준다.
    // vector는 first , second
    for(int i=0; i<n; i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    sort(a.begin(),a.end());
    for(int i=0; i < a.size(); i++){
        printf("%d %d\n",a[i].first,a[i].second);
        
    }
    
    
    return 0;
}
