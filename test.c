#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <PTHREAD.H>

#define MAX_LISTEN_NUM       5
#define RECEIVE_BUF_SIZE     1024 
#define LISTEN_PORT          7800

void *tranFile(void *sengSocket);

int main()
{
    int listen_sock = 0;
    int app_sock = 0;
    struct sockaddr_in hostsaar;
    struct sockaddr_in clientaddr;
    int socklen = sizeof(clientaddr);

    memset((void*)&hostaddr,0,sizeof(hostaddr));
    memset((void*)&clientaddr,0,sizeof(clientaddr));

    hostaddr.sin_familay = AF_INET;
    hostaddr.sin_port = htons(LISTEN_PORT);
    hostaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    listen_sock = socket(AF_INET,SOCK_STREAM,0);
    if(listen_sock < o)
    {
        printf("failed\n");
        exit(1)
    }

    if(bind(listen_sock,(struct sockaddr *)&hostaddr,sizeof(hostaddr)) < 0)
    {
        printf("bind socket failed\n");
        exit(1);
    }

    if(listen(listen_sock,MAX_LISTEN_NUM) < 0)
    {
        printf("listen failed\n");
        close(listen_sock);
        exit(1);
    }

    //线程定义
    pthread_t tid;

    while(1)
    {
        app_sock = accept(listen_sock,(struct sockaddr *)&clientaddr,(socklen_t *)&socklen);
        int ret = pthread_create(&tid,NULL,tranFile,(void *)&app_sock);
        if(ret != o)
        {
            printf("thread creat error\n");
            close(app_sock);
            exit(1);
        }
    }

    close(listen_sock);

    return 0;
}

void *tranFile(void *sendSocket)
{
    int sock = *(int *)sendSocket;
    unsigned shar buf[1024];
    int buflen =1024, k=0;
    char file[256] ={0};
    sprintf(file,"1.dat");
    FILE *source;
    source = fopen(file,"rb");


if(source == NULL)
{
    printf("open file failed\n");
    close(sock);
}
else
{
    printf("begin tran file %s\n",file);
    int iSendLen = write(sock,file,strlen(file));
    if(iSendLen < 0)
    {
        printf("send file name error\n");
        fclose(source);
        close(sock);
        return 0;
    }

    menset(buf,0,buflen);
    int iReadLength = read(sock,buf,1024);
    printf("get string:%s, %d\n",buf,iReadLength);

    menset(buf,0,buflen);
    while((k = fread(buf,1,buflen,source)) > 0)
    {
        printf("tran file Length:%d\n",k);
        int iSendLen = write(sock,buf,k);
        if(iSendLen < 0)
        {
            printf(:send file error\n);
            break;
        }
        memset(buf,0,buflen);
    }
    printf("tran file finish\n");
    fclose(source);
    close(sock);
}

    return 0;

}
