//
//  11718(그대로 출력하기).cpp
//  Algorigm_Study
//
//  Created by kgh on 15/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdio>
using namespace std;
char str[111];
int main(){
    
    while(scanf("%[^\n]\n",str) == 1){
        printf("%s\n",str);
    }
    
    return 0;
}
