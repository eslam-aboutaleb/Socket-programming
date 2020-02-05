#include "stdio.h"
#include <winsock2.h> //socket APIS
#include "Socket_interface.h"

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

