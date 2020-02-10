#ifndef CLIENTSOCKET_INTERFACE_H
#define CLIENTSOCKET_INTERFACE_H

#define Address_ByUser

#define Port 80
#define Address_Fam AF_INET



int WinSocket_Init(void);
SOCKET CreateSocket(SOCKET Soc);
void connect_Server_address(struct sockaddr_in Server_Address,SOCKET Client_Socket);

#endif // CLIENTSOCKET_INTERFACE_H
