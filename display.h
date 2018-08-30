#include "input.h"
#include "commandParser.h"
#include "execCmd.h"

char * dirName(const char * home)
{
    char *path = getenv("PWD");
    if(strlen(path) == strlen(home))
        return "~";
    else if(strlen(path) >= strlen(home))
    {
        char *relativePath = (char *)malloc(sizeof(path)+1);
        int lenHome = strlen(home);
        int lenPath = strlen(path);
        relativePath[0]='~';
        for(int i=lenHome;i<=lenPath;i++)
            relativePath[i-lenHome+1] = path[i];
        return relativePath;
    }
    return path;
}
void display(const char * home)
{
    struct utsname userInfo;
    uname(&userInfo);
    const char *sys_name = userInfo.sysname;
    const char *user_name = getenv("USER");
    printf("%s@%s:",user_name,sys_name);
    printf("%s",dirName(home));
    printf("%c",'>');
    char ** cmd;
    cmd = input();
    for(int i=0;cmd[i]!=NULL;i++)
    {
        cmd[i]=parseCommand(cmd[i]);
        execCmd(cmd[i]);
        printf("%d %s\n",i+1,cmd[i]);
    }
}
