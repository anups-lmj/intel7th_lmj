#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#define BUFFSIZE 100
void error_handling(char *message);
int main(int argc, char* argv[])
{
	fd_set reads, temps;
	int result;
	int sock;
	struct sockaddr_in serv_addr;
	char message[BUFFSIZE];
	int str_len;
	int stdin_fd=fileno(stdin);
	struct timeval timeout;
	
	printf("stdin_fd : %d\n",stdin_fd);
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
	FD_ZERO(&reads);
	FD_SET(sock,&reads);
	FD_SET(stdin_fd,&reads);

	do {
//  ---------------------- select fd:stdin_fd------------------------
	/*	fputs("문자열을 입력하세요(quit:종료) : ",stdout);
		fgets(message, sizeof(message), stdin );
		str_len = strlen(message)-1;
		message[str_len] = '\0';	//'\n'제거
		if(!strcmp(message, "quit"))
			break;

		if(str_len <= 0)
			error_handling("write() error");
*/
		temps=reads;
		timeout.tv_sec=3;
		result=select(stdin_fd+1,&temps,0,0,&timeout);
		if(result<0)
		{
			perror("select() error!");
			break;
		}
		else if(result==0)
		{
			puts("time-out");
		}
		else
		{
			if(FD_ISSET(stdin_fd,&temps))
			{
				str_len=read(0,message,BUFFSIZE);
				str_len=strlen(message)-1;
				message[str_len]=0;
				printf("message from console: %s\n",message);
				if(!strcmp(message,"quit"))
					break;
				write(sock,message,str_len);

			}


//  ------------------------------------------------------
//  ---------------------- select fd:sock ------------------------
			str_len=read(sock, message, sizeof(message)-1);
			if(str_len > 0)
			{
				message[str_len] = '\0';
				printf("Message from server: %s \n", message);
			}
			else if(str_len == 0) //서버 소켓 종료시
				break;
			else 
				error_handling("read() error!");
		}
//  ------------------------------------------------------
	} while(1);
	close(sock);
	return 0;
}
void error_handling(char *message)
{
//	perror("error_handling()");
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
