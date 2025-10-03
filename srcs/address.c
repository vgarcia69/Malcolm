#include "../includes/include.h" 
#include <ifaddrs.h>
#include <arpa/inet.h>

bool_t valid_argument(char** argv)
{
    bool_t flag = TRUE;

    if (!valid_ip_address(argv[1]))
    {
        printf("Error: source ip is invalid\n");
        flag = FALSE;
    }
    if (!valid_mac_address(argv[2]))
    {
        printf("Error: source mac address is invalid\n");
        flag = FALSE;
    }
    if (!valid_ip_address(argv[3]))
    {
        printf("Error: target ip is invalid\n");
        flag = FALSE;
    }
    if (!valid_mac_address(argv[4]))
    {
        printf("Error: target mac address is invalid\n");
        flag = FALSE;
    }
    return flag;
}

bool_t valid_ip_address(char* ip_address)
{
    struct ifaddrs *ifa_head;
    struct in_addr addr_in;

    if (inet_pton(AF_INET, ip_address, &addr_in) != 1)
        return FALSE;
    if (getifaddrs(&ifa_head) < 0)
        return FALSE;
    for (struct ifaddrs *ifa = ifa_head; ifa != NULL; ifa = ifa->ifa_next)
    {
        struct sockaddr_in *ifa_addr = (struct sockaddr_in*)ifa->ifa_addr;

        if (!ifa_addr)
            continue ;
        else if (addr_in.s_addr == ifa_addr->sin_addr.s_addr)
        {
            freeifaddrs(ifa_head);
            return TRUE;
        }
    }
    freeifaddrs(ifa_head);
    return FALSE;
}

bool_t valid_mac_address(char* mac_address)
{
    struct ifaddrs* ifa_head;
    struct in_addr  addr_in;
    unsigned char*  sll_mac_addr;

    sll_mac_addr = mac_str_to_sll(mac_address);
    if (!sll_mac_addr)
        return FALSE;
    if (getifaddrs(&ifa_head) < 0)
        return FALSE;
    for (struct ifaddrs *ifa = ifa_head; ifa != NULL; ifa = ifa->ifa_next)
    {
        struct sockaddr_ll *ifa_addr = (struct sockaddr_ll*)ifa->ifa_addr;

        if (!ifa_addr)
            continue ;
        else if (ft_strcmp(ifa_addr->sll_addr, addr_in))
        {
            freeifaddrs(ifa_head);
            free(sll_mac_addr);
            return TRUE;
        }
    }
    freeifaddrs(ifa_head);
    free(sll_mac_addr);
    return FALSE;
}

unsigned char* mac_str_to_sll(char *mac_addr)
{
    char**         octets;
    unsigned char* sll_addr;   
    char           charset[16] = "0123456789abcdef"
    
    sll_addr = malloc(sizeof(char) * 8);
    if (!sll_addr)
        return NULL;
    octets = ft_split(mac_addr, ':');
    if (!octets)
    {
        free(sll_addr);
        return NULL;
    }
    for (ssize_t i = 0; i < ft_size(octets); i++)
    {
        if (ft_strlen(octets[i]) != 2)
        {
            ft_free_tab(octets);
            free(sll_addr);
            return NULL;
        }
        // fonction qui prend B1 et le convert dans un unsgiend char
    }
}

/*



*/