#include <stdio.h>
#include <string.h>

#include <winsock2.h> //socket APIS

#pragma comment(lib , "ws2_32.lib") //means commment this part and doesnt use it



int main(void)
{
    //recieve buffer
    char buffer[2000]="";
    int recieve;

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

while(1){

    /*//////////////////////////////////////////////////////////////////////////////////////////*/
        /*                            create socket
         * ////////////////////////////////////////////////////////////////////////////////////*
        / socket(family, type, protocol);
        / family:AF_INET, IPv4 protocols, Internet addresses (typically used)
        / type: SOCK_STREAM for TCP & SOCK_DGRAM for UDP
        / protocol: IPPROTO_TCP IPPROTO_UDP usually set to 0 :default protocol which is TCP        */

        SOCKET Client_Socket; //integer to conatin socket informations

        Client_Socket=socket(AF_INET,SOCK_STREAM,0);

        if(Client_Socket==INVALID_SOCKET)
        {
            printf("Couldnt create socket : %d",WSAGetLastError());
        }
        else
        {
            printf("socket created\n");
        }


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
        Server_Address.sin_addr.s_addr=inet_addr("192.168.1.11");

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



    printf("Client:\t");
        scanf("%s",&buffer[0]);
        send(Client_Socket,buffer,strlen(buffer),0);


}

    return 0;
}


