#include <stdio.h>
#include <string.h>
#include <winsock2.h> //socket APIS
#include "Socket_interface.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/unistd.h>

#define PORT 1000

#pragma comment(lib , "ws2_32.lib") //means commment this part and doesnt use it

int main(void)
{
    char Message[50]="string";
    char buffer[2000]="";
    SOCKET Server_Socket;
    char *CHAT="";
    int i;

    //pid_t childIP;

    /*//////////////////////////////////////////////////////////////////////////////////////////*/


    //initiate windows socket
    WinSocket_Init();

    //create server socket
    Server_Socket=CreateSocket(Server_Socket);

    /*//////////////////////////////////////////////////////////////////////////////////////////*/


    //server information
    struct sockaddr_in Server_Address;
    Server_Address.sin_family=AF_INET;
    Server_Address.sin_port=htons(PORT);
    Server_Address.sin_addr.s_addr=inet_addr("192.168.3.80");

    /*//////////////////////////////////////////////////////////////////////////////////////////*/


    //bind server socket with its address
    if(bind(Server_Socket,(struct sockaddr *)&Server_Address,sizeof(Server_Address))==SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d" , WSAGetLastError());
               exit(EXIT_FAILURE);
    }
    else
    {
        printf("bind done\n");
    }

    /*//////////////////////////////////////////////////////////////////////////////////////////*/

    //number of cliens to listen
    if(listen(Server_Socket,10)==0)
    {
    printf("listening...\n");
    }
    else
    {
        printf("error in listening\n");
    }

    /*//////////////////////////////////////////////////////////////////////////////////////////*/

    SOCKET clientsocket;
    struct sockaddr_in Client_Address;
    int addlen;

while(1){
    //accept clients
    clientsocket=accept(Server_Socket,(struct sockaddr*)&Client_Address,&addlen);
    if (clientsocket<0)
    {
        printf("New client isn't accepted");
        exit(EXIT_FAILURE);
    }
   printf("Connection accepted from %s:%d\n",inet_ntoa(Client_Address.sin_addr),ntohs(Client_Address.sin_port));

while(1){

//recieve data from the client
recv(clientsocket,buffer,2000,0);
if(strcmp(buffer,"")!=0){
        printf("Recieved: %s\n",buffer);
    }

    /*//////////////////////////////////////////////////////////////////////////////////////////*/

//check if the client want to disconnect
if(strcmp(buffer,"quit")==0)
    {
    //close client socket
        closesocket(clientsocket);
        printf("Client %s:%d disconnected\n",inet_ntoa(Client_Address.sin_addr),ntohs(Client_Address.sin_port));
        break;
    }

    /*//////////////////////////////////////////////////////////////////////////////////////////*/


//send the recieved buffer
send(clientsocket,buffer,strlen(buffer),0);


    /*//////////////////////////////////////////////////////////////////////////////////////////*/


//empty all the buffer or use memset function
for(i=0;i<sizeof(buffer);i++){
    buffer[i]='\0';
}
}

}

   /*//////////////////////////////////////////////////////////////////////////////////////////*/

//close the server
     closesocket(Server_Socket);

    return 0;

}
