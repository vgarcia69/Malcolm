#include "../includes/include.h" 
#include <ifaddrs.h>
#include <arpa/inet.h>

static bool_t valid_octet(char* str_octet);

bool_t valid_ip_address(char* ip_address)
{
    ssize_t len;
    char**  oct;

    len = ft_strlen(ip_address);
    if (len < 7 || len > IP_ADDRESS_SIZE)
        return FALSE;

    oct = ft_split(ip_address, ':');
    if (ft_size(oct) != 4)
        return FALSE;

    for (int i = 0 ; oct[i]; i++)
    {
        if (!valid_octet(oct[i]))
        {
            ft_free_tab((void**)oct);
            return FALSE;
        }
    }
    ft_free_tab((void**)oct);
    return exist_ip_address(ip_address);
}

static bool_t valid_octet(char* str_octet)
{
    ssize_t len;
    int     int_octet;

    len = ft_strlen(str_octet);
    if (len > 3 || len < 0)
        return FALSE;

    int_octet = ft_atoi(str_octet);
    if (int_octet < 0 || int_octet > 255)
        return FALSE;

    return TRUE;
}

static bool_t exist_ip_address(char* ip_address)
{
    struct ifaddrs *ifa_head;

    getifaddrs(&ifa_head);
    for (struct ifaddrs *ifa = ifa_head; ifa != NULL; ifa = ifa->ifa_next)
    {
        struct sockaddr_in *ifa_addr = ifa->ifa_addr;
        int current_addr = ntohs(ifa_addr->sin_addr);
    }
    freeifaddrs(ifa_head);
    return TRUE;
}