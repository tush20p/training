/*implement a full-duplex client server application using socket*/

#include"../inc/11_tcp.h"
void main()
{
	char s[20];
	int i,sfd,r,len,nsfd;
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
	v.sin_addr.s_addr=inet_addr("0.0.0.0");

	len=sizeof(v);
	r=bind(sfd,(struct sockaddr *)&v,len);

	if(r<0)
	{
		perror("bind");
		return;
	}

	perror("bind");

	//////////////////////////////////////////////////////

	listen(sfd,5);
	perror("listen");

	////////////////////////////////////////////////////

	nsfd=accept(sfd,(struct sockaddr *)&v1,&len);

	if(nsfd<0)
	{
		perror("accept");
		return;
	}

	perror("accept");

	/////////////////////////////////////////////////////


	if(fork()==0)
	{
		while(1)
		{
			read(nsfd,s,sizeof(s));
			printf("data=%s\n",s);
		}

	}
	else
	{
		while(1)
		{
			printf("Enter the data\n");
			scanf("%s",s);

			write(nsfd,s,strlen(s)+1);

		}

	}
}






