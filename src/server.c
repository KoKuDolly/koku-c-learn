
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#ifdef __WIN32__
#include <winsock.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#endif

#pragma comment(lib, "Ws2_32.lib")

#define PORT 23
#define BACKLOG 5
 
int main()
{
	int iSocketFD = 0;
	int iRecvLen = 0;
	int new_fd = 0;
	char buf[4096] = {0};
	struct sockaddr_in stLocalAddr = {0};
	struct sockaddr_in stRemoteAddr = {0};
	socklen_t socklen = 0;
 
	iSocketFD = socket(AF_INET, SOCK_STREAM, 0);
	if(0 > iSocketFD)
	{
		printf("创建socket失败！\n");
		exit(1);
	}	
 
	stLocalAddr.sin_family = AF_INET;
	stLocalAddr.sin_port = htons(PORT);
	stLocalAddr.sin_addr.s_addr=htonl(INADDR_ANY);
 
	if(0 > bind(iSocketFD, (void *)&stLocalAddr, sizeof(stLocalAddr)))
	{
		perror("bind");
		exit(1);
	}
 
	if(0 > listen(iSocketFD, BACKLOG))
	{
		perror("listen");
		exit(1);
	}
 
	printf("iSocketFD: %d\n", iSocketFD);	
	new_fd = accept(iSocketFD, (void *)&stRemoteAddr, &socklen);
	if(0 > new_fd)
	{
		perror("accept");
		exit(1);
	}else{
		printf("接收成功！\n");
		send(new_fd, "这是服务器接收成功后发回的信息!", sizeof("这是服务器接收成功后发回的信息!"), 0);
	}
 
	printf("new_fd: %d\n", new_fd);	
	iRecvLen = recv(new_fd, buf, sizeof(buf), 0);	
	if(0 >= iRecvLen)
	{	
		printf("接收失败或者对端关闭连接！\n");
	}else{
		printf("buf: %s\n", buf);
	}
 
	closesocket(new_fd);
	closesocket(iSocketFD);
 
	return 0;
}
