//
//  1182 부분집합의 합.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 25/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
int ans;
int recursive(int sum,vector<int> v, int cnt){
    
    // True
    if(sum == m && cnt == n){
        return 1;
    }
    // False
    if(cnt == n){
        return 0;
    }
    
    int res = 0;
    res += recursive(sum+v[cnt], v, cnt+1);
    res += recursive(sum,v,cnt+1);
    
    return res;

}
int main(void){
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<v.size(); i++){
        cin >> v[i];
    }
    ans = recursive(0,v,0);
    if (m == 0) ans -= 1;
    cout << ans << '\n';
    return 0;
}
