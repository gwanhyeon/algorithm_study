//
//  1406(에디터).cpp
//  Algorigm_Study
//
//  Created by kgh on 16/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char ch[600000];

int main(void){
    // 길이가 600,000을 넘지 않는 문자열 입력
    scanf("%s",ch);
    // 명령 몇번 실행할지 여부
    
    // stack 2개를 사용하여 커서를 확인할것이기 때문에 left,right선언
    stack<char> left,right;
    int n = strlen(ch);
    // stack left에 값들 모두 넣어주기, right는 나중에 커서 위치확인하려고 사용할것임.
    for(int i=0; i<n; i++){
        left.push(ch[i]);
    }
    int num;
    scanf("%d",&num);
    // 몇번의 명령을 실행할것인지에 대한것
    while(num--){
        // 명령 입력
        char command;
        scanf(" %c",&command);
        
        // 'L'일경우 커서를 왼쪽으로 옮김 == 왼쪽 스택에 있는 top부분을 빼서 오른쪽 스택에 넣는다.
        if(command == 'L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }else if(command == 'D'){  // 'D'일경우 커서를 오른쪽으로 한칸 옮긴다.
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }else if(command == 'B'){  // 'B'일경우 왼쪽에 있는 커서를 삭제한다. (top부분)
            if(!left.empty()){
                left.pop();
            }
        }else if(command == 'P'){ // 'P'입력시 $부분을 새로 입력받기 위함.
            char p_string;
            scanf(" %c",&p_string);
            left.push(p_string);
        }
    }
    // left stack에 있는값들을 모두 오른쪽으로 옮기고 stack 에서 pop해준다.
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    // left stack에서 값을 모두 옮겼으니까 stack top부분에 있는값들을 하나씩 출력해주면서 뺴준다.
    while(!right.empty()){
        printf("%c",right.top());
        right.pop();
    }
    printf("\n");
    return 0;
}
