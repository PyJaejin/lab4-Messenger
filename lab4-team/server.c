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


	//서버 코드는 추후 작성 예정 .. 아직 틀만 작성했음
}
