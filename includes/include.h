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

    bool_t valid_ip_address(char* ip_address);

#endif
