//
//  BC(baseconversion).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main(void){
    
    int n,b;
    cin >> n >> b;
    string ans = "";
    string test = "f";
    

    
    while(n > 0){
        int r = n % b;
        
        if(r < 10){
            // 10이하값을 문자열로 저장한다.
            ans += (char)(r +'0');
        }else {
            // 10 이상 값일 경우
            // -10을 해주는이유는 10부터 값만 사용할것이므로 대문자로 r-10을 해준다.
            ans += (char)(r - 10 + 'A');
        }
        
        n /= b; // 계속 값을 갱신시켜주기 위해서 n값에 저장하면서 간다.
    }
    
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    
    
    return 0;
}
