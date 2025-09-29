#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);
int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	char message[100];
	int str_len;
	int i=0;
	if(argc!=3){
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sock < 0)
		error_handling("socket() error");
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));
	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
		error_handling("connect() error!");
	do {
		printf("문자열을 입력하세요(quit:종료) : ");
		fgets(message,sizeof(message),stdin);
		message[strlen(message-1)]='\0';
		if(strcmp(message,"quit")==0)
		{
			break;
		}
		str_len = write(sock,message,strlen(message));    //키보드 입력 문자열을 서버로 전송
		if(str_len <=0)
			error_handling("write() error!");
		str_len=read(sock, message, sizeof(message)-1);
		
		if(str_len > 0)
		{
			message[str_len]='\0';
			printf("Message from server: %s \n",message);
		}
		else if(str_len==0)//서버 소켓 종료시 
			break;
		else
		{
			error_handling("read() error!");
		}
		
	} while(1);
	close(sock);
	return 0;
}
void error_handling(char *message)
{
	perror("error_handling()");
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
