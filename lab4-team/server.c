#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define MAXCLIENT 5

struct _user_info
{
    char id[30];
    char pw[30];
} user_info, user_info_chk;

int main(int argc, char **argv)
{ 
    FILE *fp;


    fp = fopen("user_info.txt", "r");
    i=0;
    while(!feof(fp)) {
        fgets(idList[i++], 20, fp);
    }
    j = i-1;
    for(i=0; i<j; i++) {
        printf("등록된 사용자 목록[%d번]: %s\n", i+1, idList[i]);
    }
    fclose(fp);
}
