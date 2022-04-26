#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#define SEND_BUF_SIZE 100
#define RECV_BUF_SIZE 100
#define server_port 7801

int main(int argc, char const *argv[])
{
    //定义socket
    int sock_fd=0;
    //定义发送数据的内存
    char sendbuf[SEND_BUF_SIZE] = {0};
    //定义接受数据中长度
    int sendlen= 0;

    //定义服务器的socket的通讯地址
    struct sockaddr_in ser_addr;

    //设置服务器的socket参数
    memset(&ser_addr,0,sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    inet_aton("127.0.0.1",(struct in_addr *)&ser_addr.sin_addr);
    ser_addr.sin_port = htons(SERVER_PORT);

    //创建socket
    sock_fd = socket(AF_INET_DGRAM,0);
    if(sock_fd < 0)
    {
        printf("creat socket failed\n");
        exit(1);
    }

    //发送数据
    sprintf(sendbuf,:hello server);
    sendlen = strlen(sendbuf) + 1;
    int iRealSend = sendto(sock_fd, sendbuf, sendlen, o,
                   (struct sockaddr*)(&ser_addr),sizeof(struct sockaddr_in));

    printf("send data is : %s, send length:%d\n", sendbuf, iRealSend);

    //关闭socket
    close(sock_fd) 
    
    return 0;
}

