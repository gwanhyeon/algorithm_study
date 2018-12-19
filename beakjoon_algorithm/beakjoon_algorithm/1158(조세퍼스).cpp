//
//  1158(조세퍼스문제).cpp
//  Algorigm_Study
//
//  Created by kgh on 16/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int main(void){
    
    // N,M 입력하기 예를들어 (7,3) 일경우 1~7(N)까지의 수중에서 M번째 맨앞에 수를 제거하면서 조세퍼스 순열을 만들어준다.
    
    int N,M;
    int cnt=1;
    queue<int> q,result;
    scanf("%d %d", &N, &M);
    
    // queue에 1 ~ N 까지의 값 push
    
    for(int i=0; i<N; i++){
        q.push(cnt);
        cnt++;
    }
    printf("<");
    // N의 범위 만큼 실행시켜준다 N = 7 일경우
    for(int i=0; i<N-1; i++){
        // M의 범위 만큼 실행시켜준다 M= 3 일경우
        for(int j=0; j<M-1; j++){
            // 가장 맨앞에 있는 값들을 맨 뒤로 돌리는 과정
            q.push(q.front());
            // 그리고 맨앞에 있는 값을 pop
            q.pop();
            
        }
        // 이중포문에 안쪽포문이 끝나게 되면 맨앞에는 결국 삭제되어야하는 값이 남게됩니다.
        printf("%d, ", q.front());
        q.pop();
    }
    printf("%d>\n",q.front());

    
    return 0;
}


////
////  1158(조세퍼스문제).cpp
////  Algorigm_Study
////
////  Created by kgh on 16/12/2018.
////  Copyright © 2018 kgh. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <queue>
//
//using namespace std;
//int main(void){
//
//    // N,M 입력하기 예를들어 (7,3) 일경우 1~7(N)까지의 수중에서 M번째 맨앞에 수를 제거하면서 조세퍼스 순열을 만들어준다.
//
//    int N,M;
//    int cnt=1;
//    queue<int> q,result;
//    scanf("%d %d", &N, &M);
//
//    // queue에 1 ~ N 까지의 값 push
//
//    for(int i=0; i<N; i++){
//        q.push(cnt);
//        cnt++;
//    }
//
//    // queue가 빌때 까지 계속 수행한다.
//    for(int i=0; i<N-1; i++){
//        for(int j=0; j<M-1; j++){
//            q.push(q.front());
//            q.pop();
//
//        }
//        result.push(q.front());
//        q.pop();
//    }
//    for(int i=0; i<result.size(); i++){
//        printf("%d ",result.front());
//        result.pop();
//    }
//
//    return 0;
//}
