#include <stdio.h>
#include <string.h>
#include <winsock2.h> //socket APIS
#include "ClientSocket_interface.h"


#pragma comment(lib , "ws2_32.lib") //means commment this part and doesnt use it

int main(void)
{
    //recieve buffer
    char buffer[2000]="";
    char server_reply[2000]="";
    int Recieve_Status;

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

    struct sockaddr_in Server_Address;
    connect_Server_address(Server_Address,Client_Socket);


/*///////////////////////////////////////////////////////////////////////////////////////////*/
    /*                               send & recieve                                         */
/*///////////////////////////////////////////////////////////////////////////////////////////*/

char message[2000] = "GET https://api.thingspeak.com/update?api_key=Q42W5HVOFFH1B2NS&field1=200\r\n\r\n";
char API_KEY[50]="Q42W5HVOFFH1B2NS";

        if( send(Client_Socket , message , strlen(message) , 0) , 0)
        {
                    puts("Send failed");
                    return 1;
        }
        else
        {
        puts("Field 1 value has changed.");

        }
        if((Recieve_Status = recv(Client_Socket , server_reply , 2000 , 0)) == SOCKET_ERROR)
                  {
                      puts("recv failed");
                  }
        if( send(Client_Socket , message , strlen(message) , 0) , 0)
        {
                    puts("Send failed");
                    return 1;
        }


                  //Add a NULL terminating character to make it a proper string before printing
                  puts(server_reply);

    return 0;
}

