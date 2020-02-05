#include <stdio.h>
#include <string.h>

#include <winsock2.h> //socket APIS
#include "Socket_interface.h"

#pragma comment(lib , "ws2_32.lib") //means commment this part and doesnt use it

int main(void)
{
    //to initialize windows socket data
   WinSocket_Init();


/*//////////////////////////////////////////////////////////////////////////////////////////*/
    /*                            create socket
     * ////////////////////////////////////////////////////////////////////////////////////*
    / socket(family, type, protocol);
    / family:AF_INET, IPv4 protocols, Internet addresses (typically used)
    / type: SOCK_STREAM for TCP & SOCK_DGRAM for UDP
    / protocol: IPPROTO_TCP IPPROTO_UDP usually set to 0 :default protocol which is TCP        */

    SOCKET Client_Socket; //integer to conatin socket informations
    Client_Socket=CreateSocket(Client_Socket);



 /*///////////////////////////////////////////////////////////////////////////////////////////*/

    //                             connect to the socket

    /*//////////////////////////////////////////////////////////////////////////////////////*/


    struct sockaddr_in Server_Address; //create structure for socket address
    //clear the structure
    memset(&Server_Address,'\0',sizeof(Server_Address));

    Server_Address.sin_family=AF_INET;

    //80 is host short for http ... htons translate data to different platforms ex:from big endian to little endian
    Server_Address.sin_port=htons(1000);

     //specify address to connect //INADDR_ANY
    Server_Address.sin_addr.s_addr=inet_addr("192.168.3.80");

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

/*///////////////////////////////////////////////////////////////////////////////////////////*/
    /*                               send & recieve                                         */
/*///////////////////////////////////////////////////////////////////////////////////////////*/

    //sent message
    char Message[50]="GET /  HTTP/1.1\r\n\r\n";
    //recieve buffer
    char buffer[2000]="";
    int recieve;

while(1){
    printf("Client:\t");
        scanf("%s",&buffer[0]);
        send(Client_Socket,buffer,strlen(buffer),0);
        recieve=recv(Client_Socket,buffer,2000,0);

        printf("Server:\t%s\n",buffer);

        if(recieve<0)
        {
            printf("error while recieving data");
        }
        if(strcmp(buffer,"quit")==0)
        {
            closesocket(Client_Socket);
            printf("disconnected from server \n");
            exit(1);
        }
}

    return 0;
}

