#include "../includes/include.h" 
#include <ifaddrs.h>
#include <arpa/inet.h>

bool_t valid_ip_address(char* ip_address)
{
   struct ifaddrs *ifa_head;

    getifaddrs(&ifa_head);
    for (struct ifaddrs *ifa = ifa_head; ifa != NULL; ifa = ifa->ifa_next)
    {
        struct sockaddr_in *ifa_addr = ifa->ifa_addr;
        struct sockaddr_in *addr_in;

        if (!inet_pton(IF_INET, ip_address, &addr_in))
            break ;
        if (addr_in->sin_addr == ifa_addr->sin_addr)
        {
            freeifaddrs(ifa_head);
            return TRUE;
        }
    }
    freeifaddrs(ifa_head);
    return FALSE;
}
