//
//  1107리모컨.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
#include <stdio.h>
#include <iostream>
using namespace std;
bool broken[10];
int possible(int c){
    // 0번째 일경우에는 아무런 변화도 일어나지 않으므로;
    if(c == 0){
        if(broken[0]){
            return 0;
        }else {
            return 1;
        }
    }
    int len = 0;
    // 몇자리의 수로 이동하는지
    while(c > 0){
        if(broken[c % 10]){
            return 0;
        }
        len +=1;
        c /= 10;
    }
    return len;
}
int main(void){
    /*
     첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.  둘째 줄에는 고장난 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다.
     */
    int n, m;       // n = 이동하려고 하는 채널 , m = 고장난 버튼의 개수
    cin >> n;
    cin >> m;
    
    // 고장난 채널들 체크하기(고장난 버튼의 개수만큼 = m)
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        broken[x] = true;
    }
    
    int ans = n - 100;          // 수빈이는 100번째에 위치해있으므로
    // 위치값이 음수일 경우 절대값을 씌워준다.
    if(ans < 0){
        ans = -ans;
    }
    // 모든 경우의 수를 다 따져보는것임(양 / 음) 0 ~ 1000000
    for(int i=0; i <= 1000000; i++){
        int c = i;
        int len = possible(c);
        
        if(len > 0){
            int press = c - n;      // 채널 0 ~ 1,000,000 까지 값을 다 확인하면서 이동해야되는 채널을 뺀다.
            if(press < 0 ){     // 그값이 음수 일 경우 절대값을 씌워서 확인한다.
                press = -press;
            }
            // 만약 결과값이 반환된 길이와 눌려진값보다 클 경우에 그값을 len+press값으로 변경한다. len값은 현재 몇번째자리의 값인지의 값이고 press값은 +,-값을 의미한다.
            if(ans > len + press){
                ans = len + press;
            }
        }
    }
    cout << ans;
    
    return 0;
    
    
}
