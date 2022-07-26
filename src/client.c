#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#ifdef __WIN32__
	#include <winsock2.h>
	#include <ws2tcpip.h>
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netinet/ip.h>
	#include <arpa/inet.h>
#endif

 
#define PORT 23
#define ADDR "127.0.0.1"

int main()
{
	int iSocketFD = 0;
	unsigned int iRemoteAddr = 0;
	struct sockaddr_in stRemoteAddr = {0};
	socklen_t socklen = 0;  	
	char buf[4096] = {0};
 
	iSocketFD = socket(AF_INET, SOCK_STREAM, 0);
	if(0 > iSocketFD)
	{
		printf("创建socket失败！\n");
		return 0;
	}	
 
	stRemoteAddr.sin_family = AF_INET;
	stRemoteAddr.sin_port = htons(PORT);
	inet_pton(AF_INET, ADDR, &iRemoteAddr);
	stRemoteAddr.sin_addr.s_addr=iRemoteAddr;
	
	if(0 > connect(iSocketFD, (void *)&stRemoteAddr, sizeof(stRemoteAddr)))
	{
		perror("connect");
	}else{
		printf("连接成功！\n");
		recv(iSocketFD, buf, sizeof(buf), 0);
		printf("Received:%s\n", buf);
	}

	close(iSocketFD);
	return 0;
}
