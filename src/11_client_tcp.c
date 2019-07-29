/*implement a full-duplex client server application using socket*/

#include"../inc/11_tcp.h"
void main()
{
	char s[20];
	int i,sfd,r,len,nsfd,m;
	struct sockaddr_in v,v1;

	sfd=socket(AF_INET,SOCK_STREAM,0);

	if(sfd<0)
	{
		perror("socket");
		return;
	}

	perror("socket");
	printf("sfd=%d\n",sfd);


	///////////////////////////////////////////////////

	v.sin_family=AF_INET;
	v.sin_port=htons(3000);
	v.sin_addr.s_addr=inet_addr("127.0.0.1");

	len=sizeof(v);
	m=connect(sfd,(struct sockaddr *)&v,len);

	if(m<0)
	{
		perror("connect");
		return;
	}

	perror("connect");

	//////////////////////////////////////////////////////


	if(fork()==0)
	{
		while(1)
		{
			read(sfd,s,sizeof(s));
			printf("data=%s\n",s);
		}

	}
	else
	{
		while(1)
		{
			printf("Enter the data\n");
			scanf("%s",s);

			write(sfd,s,strlen(s)+1);

		}

	}
}






