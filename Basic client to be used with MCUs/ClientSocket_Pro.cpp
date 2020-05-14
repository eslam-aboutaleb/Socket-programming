#include <stdio.h>
#include <winsock2.h> //socket APIS
#include "ClientSocket_interface.h"

char AddressByUserID[100]= "52.86.196.73";

int WinSocket_Init(void){
    //to initialize windows socket data
    WSADATA wsa;
    int WSAcheck;
    printf("\ninitializing winsock...");

    if ((WSAcheck=WSAStartup(MAKEWORD(2,2),&wsa))!=0)
    {
        printf("failed. error code : %d",WSAGetLastError());
        return 1;
    }

else{
    printf("Initialized\n");
    }
    return WSAcheck;
}


SOCKET CreateSocket(SOCKET Soc)
{
    Soc=socket(AF_INET,SOCK_STREAM,0);

    if(Soc==INVALID_SOCKET)
    {
        printf("Couldnt create socket : %d",WSAGetLastError());
    }
    else
    {
        printf("socket created\n");
    }
    return Soc;
}


void connect_Server_address(struct sockaddr_in Server_Address,SOCKET Client_Socket){
//clear the structure
memset(&Server_Address,'\0',sizeof(Server_Address));

Server_Address.sin_family=Address_Fam;

//80 is host short for http ... htons translate data to different platforms ex:from big endian to little endian
Server_Address.sin_port=htons(Port);
#ifdef Address_ByUser

 //specify address to connect
Server_Address.sin_addr.s_addr=inet_addr(AddressByUserID);
#endif

#ifndef Address_ByUser
Server_Address.sin_addr.s_addr=INADDR_ANY;
#endif

//connect(sockid, &foreignAddr, addrlen);
int Connection_Status=connect(Client_Socket,(struct sockaddr *)&Server_Address,sizeof(Server_Address));

//check if the connection failed
if(Connection_Status==-1)
{
    printf("Connection failed\n");
    exit(1);
}
else
{
    printf("Connected to server:\t%s:%d\n",inet_ntoa(Server_Address.sin_addr),ntohs(Server_Address.sin_port));
}

}

