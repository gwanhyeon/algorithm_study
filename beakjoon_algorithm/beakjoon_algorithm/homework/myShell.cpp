
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


#define MAX 1024        // 초기값 설정
char* buf[MAX];         // 저장공간 buf 초기값 MAX

// Function 1. unix command mv

void mymv(int argc,char *argv[])
{
    char* pathname;
    //3 arguments in command line
    if(argc==3)
    {
        //check if file to be moved exists
        if((access(argv[1],F_OK|W_OK))==0)
        {
            //append name of the file to the given path name
            pathname = strcat(argv[2], argv[1]);
            //if link is succesfully created
            if(link(argv[1],argv[2])==0)
            {
                //if file argv[1] is deleted from its original location
                if((unlink(argv[1]))==0)
                {
                    printf("%s succesfully moved to %s\n",argv[1],argv[2]);
                }
                else
                {
                    //file argv[1] was not unlinked from original location
                    perror("Link deletion error");
                }
            }
            //link creation failed
            else
            {
                perror("Link creation error");
            }
        }
        
        //file argv[1] does not exist
        else
        {
            perror("File error");
        }
    }
    //invalid number of arguments
    else
    {
        printf("Invalid number of arguments : <command> <filename> <pathname/>\n");
    }
    
    
}


void mycp(int argc,char *argv[])
{
    int fd1, fd2;
    //valid number of arguments
    if(argc==3)
    {
        fd1=open(argv[1],O_RDONLY);
        //check if file is opened
        if(fd1==-1)
        {
            perror("File creation error");
        }
        //file created : file descriptor returned
        else
        {
            fd2=open(argv[2],O_WRONLY|O_CREAT,0777);
            //if file is created
            if(fd2!=-1)
            {
                if(read(fd1,buf,MAX)!=-1)
                {
                    if(write(fd2,buf,MAX)!=-1)
                    {
                        printf("File %s copied to %s\n",argv[1],argv[2]);
                    }
                    
                }
                //file had read/write errors; hence delete the 2nd file created
                else
                {
                    if(!unlink(argv[2]))
                    {
                        printf("File had read/write errors; hence delete the 2nd file created");
                    }
                }
                
            }
            
        }
    }
    //invalid number of arguments
    else
    {
        printf("Error: Enter command followed by file to be copied and destination file\n");
        
    }
    
    
}



int main()
{
    char getCommand[MAX];
    char *tokens[MAX];
    int cnt;
    char *cwd;
    char host_name[MAX] = {"",};
    char user_name[MAX] = {"",};
    int len = MAX;
    cwd = getcwd(NULL,BUFSIZ);
    getlogin_r(user_name,len);
    gethostname(host_name,len);
    
    while(1) //Run the loop until the user wants to exit the Mini Shell.
    {
        cnt=0;
        printf("%s:%s$ ",host_name,cwd);
        // 줄바꿈 문자 제거
        fgets(getCommand,sizeof(getCommand)-1,stdin);
        tokens[cnt++]=strtok(getCommand," \n"); //Extract the first token from getcommand.
        
        while((tokens[cnt++] = strtok(NULL," \n"))); //Extract all the arguments to the command and store them in tokens.
        if(!strcmp(tokens[0],"exit")) //The user wishes to exit the Mini Shell.
        {
            exit(0); //Terminate the Mini Shell.
        }
        else if(!strcmp(tokens[0],"cp")) //The user wishes to execute the copy(cp) command..
        {
            mycp(cnt-1,tokens); //Call mycp function with number of argumemts and the argument list as parameters.
        }
        else if(!strcmp(tokens[0],"mv")) //The user wishes to execute the my command.
        {
            mymv(cnt-1,tokens); //Call mymv function with number of arguments and the argument list as paramaters.
        }
        else if(!strcmp(tokens[0], "clear")) //The user wishes to execute the clear command.
        {
            system("clear");
        }
    }
    return 0;
}

