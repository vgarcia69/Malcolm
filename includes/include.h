#ifndef INC_H
    #define INC_H

    #include <stdio.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <linux/if_ether.h> 
    #include <arpa/inet.h>
    #include <linux/if_packet.h>
    #include <net/if.h>
    #include <ifaddrs.h>
    #include <arpa/inet.h>
    #include <linux/if_packet.h>
    #include "../libft/libft.h"

    #define ERROR 2
    #define TRUE  1
    #define FALSE 0
    #define IP_ADDRESS_SIZE 16

    typedef unsigned char bool_t;

    bool_t valid_argument(char** argv, struct ifaddrs* ifa_head);
    bool_t wait_request(int* fd_socket, unsigned char buffer[2048]);
    bool_t send_reply(int* fd_socket, unsigned char* buffer);

#endif
