//
//  10808(알파벳개수).cpp
//  Algorigm_Study
//
//  Created by kgh on 18/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 문자열 입력
    string str;
    cin >> str;
    
    // 시간복잡도 : O(N)
    int cnt=0;
    int freq[26]= {};       // 0 init
    for(int i='a'; i<='z'; i++){
        // str문자열 처음부터 끝까지 'a'값부터 'z'값까지의 개수를 세서 반환한다.
        // Example: hello 일경우 'a'부터 값을 hello전체를 탐색해서 개수를 반환한다. 그이후 'b' ~ 'z'까지 탐색
        // solution 1
        cout << count(str.begin(), str.end(), i) << ' ' ;
        
        // solution 2
//        for(auto s : str){
//            cnt += (s == str);
//        }
  
    
    }
    // solution 3
    for(auto s : str){
        freq[s-'a']++;
        
    }
    // solution 3 출력
    for(int i=0; i<26; i++){
        cout << freq[s-'a'];
    }
    printf("\n");
    
    return 0;
}
