#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct card {
    
    char Last_name[20];
    char First_name[20];
    char SSN[20];
    char test1[20];
    char test2[20];
    char test3[20];
    char test4[20];
    char test5[20];
    char grade[20];
    
};

int main( void){
    FILE *rfp;
    char buf[255];
//    char *ptr;
    char *name;
    int average;
    int i=0,j=0,k=0;
    
    struct card gc[20];
    
    if ((rfp = fopen("/Users/kgh/Development/Algorithm_CodingTest/algorithm_study/beakjoon_algorithm/beakjoon_algorithm/grades.csv", "r")) == NULL) {
        perror("fopen: grades.csv");
        exit(1);
    }
    
    while (fgets(buf, sizeof(buf) ,rfp) != NULL) {
        
        char* ptr = strtok(buf, " \",");
        j=0;
        
        while (ptr != NULL){
            
            if(i!=0){
                switch(j){
                    case 0:
                        strcpy(gc[i].Last_name,ptr);
                        break;
                    case 1:
                        strcpy(gc[i].First_name,ptr);
                        break;
                    case 2:        strcpy(gc[i].SSN,ptr); break;
                    case 3:        strcpy(gc[i].test1,ptr); break;
                    case 4:        strcpy(gc[i].test2,ptr); break;
                    case 5:        strcpy(gc[i].test3,ptr); break;
                    case 6:        strcpy(gc[i].test4,ptr); break;
                    case 7:         strcpy(gc[i].test5,ptr); break;
                    case 8:        strcpy(gc[i].grade,ptr); break;
                    default: break;}
                
                printf("%s ",ptr);
                ptr = strtok(NULL, " \",");
                j++;
            }
            
            i++;
            
            if(i>20){
                printf("저장공간을 초과했습니다.");
                exit(1);
            }
        }
    }
    
    
    printf("평균값을 구하고자 하는 Last_name을 적으세요.\n");
    printf("Last_name : ");
    scanf("%s",&name);
    
    for(k=0; k<20 ;k++){
        if(gc[k].Last_name == name) break;
    }
    
    if(k==20){
        printf("찾고자하는 이름이 없습니다.\n");
        exit(1);
    }
    
    printf("%s",name);
    
    int a,b,c,d,e;
    a = atoi(gc[k].test1);
    b = atoi(gc[k].test2);
    c = atoi(gc[k].test3);
    d = atoi(gc[k].test4);
    e = atoi(gc[k].test5);
    
    average = a + b + c + d + e;
    average = average/5;
    printf("%d",average);
    
    fclose(rfp);
    
    return 0;
}
