#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <time.h>


// 쓰레드 동작시 실행될 함수
void *threadRun(void* port)
{
    char thread_msg[30] = "./server ";
    int port_recv = *(int *)port;
    char port_char[10];

    sprintf(port_char, "%d", port_recv);
    strcat(thread_msg, port_char);
    system(thread_msg);
}



int main(int argc, char** argv)
{
    pthread_t jaejinThread[5];
    int threadErr;
    int i=0;
    int port=0;
    int* p;

    while(1) {
        printf("port? : ");
        scanf(" %d", &port);
        p = &port;
        // 쓰레드를 만들고 쓰레드 함수 실행
        if(threadErr = pthread_create(&jaejinThread[i], NULL, threadRun, p))
        {
            // 에러시 에러 출력
            printf("Thread Err = %d",threadErr);
        }
        i++;
    }
    while(1);
}
