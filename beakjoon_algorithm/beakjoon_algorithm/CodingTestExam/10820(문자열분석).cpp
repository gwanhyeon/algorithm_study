
//
//  10820(문자열분석).cpp
//  Algorigm_Study
//
//  Created by kgh on 20/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

int main(void){
    
    
    // 1. 총 몇개의 문자열을 입력할것인지
    
    string str;
    // 2.문자열 탐색
    while(getline(cin,str)){
        // 3. 문자열 입력
        
        int num[4] ={0,};
    
        for(char c : str){
            if(c >= 'a' && c <= 'z'){
                num[0] += 1;
                
            }else if(c >='A' && c <= 'Z'){
                num[1] += 1;
                
            }else if(c >='0' && c <='9'){
                num[2] += 1;
                
            }else if(c ==' '){
                num[3] += 1;
            }
        }
        cout << num[0] <<' '<<num[1] << ' '<< num[2] << ' ' <<num[3] <<endl;
    }
    cout <<endl;
    
    return 0;
}
