//
//  main.c
//  Algorigm_CodingTest
//
//  Created by kgh on 2018. 4. 2..
//  Copyright © 2018년 kgh. All rights reserved.
//

#include <stdio.h>

int main() {
   
    int temp=0;
    int a,b;
    int c;
    scanf("%d",&temp);
    while(temp--){
        
        c = scanf("%d %d",&a,&b);
        printf("Sum: %d\n",a+b);
        
        printf("%d",c);
        
    }
    
    return 0;
}

