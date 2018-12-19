//
//  10809(알파벳찾기).cpp
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
    string str;
    cin >> str;
    
    int idx = 0;
    // string함수를 사용하면 첫번째 인덱스를 찾는문자의첫번째 인덱스만 발견해서 반환해주고, 못찾을 경우 -1을 출력해준다.
    for(int i='a'; i<='z'; i++){
        idx = str.find(i);
        cout << idx << ' ';
    }
    cout << endl;
}
