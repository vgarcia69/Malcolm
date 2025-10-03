#ifndef INC_H
    #define INC_H

    #include <stdio.h>
    #include <unistd.h>
    #include "../libft/libft.h"

    #define ERROR 2
    #define TRUE  1
    #define FALSE 0
    #define IP_ADDRESS_SIZE 16

    typedef unsigned char bool_t;

    bool_t valid_argument(char** argv);
    bool_t valid_ip_address(char* ip_address);
    bool_t valid_mac_address(char* mac_address);

#endif
