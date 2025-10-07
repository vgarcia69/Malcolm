#include "../includes/include.h" 

static bool_t         valid_ip_address(char* ip_address, struct ifaddrs* ifa_head, bool_t flag);
static bool_t         valid_mac_address(char* mac_address, struct ifaddrs* ifa_head);
static unsigned char* mac_str_to_sll(char *mac_addr);
static unsigned char  parse_byte(char* str);
static int            hex_char_to_value(char c);

bool_t valid_argument(char** argv, struct ifaddrs* ifa_head)
{
    bool_t flag = TRUE;

    if (!valid_ip_address(argv[1], ifa_head, TRUE))
    {
        printf("ft_malcolm: unknown host or invalid IP address: (%s).\n", argv[1]);
        flag = FALSE;
    }
    if (!valid_mac_address(argv[2], ifa_head))
    {
        printf("ft_malcolm: unknown host or invalid MAC address: (%s).\n", argv[2]);
        flag = FALSE;
    }
    if (!valid_ip_address(argv[3], ifa_head, FALSE))
    {
        printf("ft_malcolm: unknown host or invalid IP address: (%s).\n", argv[3]);
        flag = FALSE;
    }
    if (!valid_mac_address(argv[4], ifa_head))
    {
		printf("ft_malcolm: unknown host or invalid MAC address: (%s).\n", argv[4]);
        flag = FALSE;
    }
    return flag;
}

static bool_t valid_ip_address(char* ip_address, struct ifaddrs* ifa_head, bool_t flag)
{
    struct in_addr addr_in;

    if (inet_pton(AF_INET, ip_address, &addr_in) != 1)
        return FALSE;
    for (struct ifaddrs *ifa = ifa_head; ifa != NULL; ifa = ifa->ifa_next)
    {
        struct sockaddr_in *ifa_addr = (struct sockaddr_in*)ifa->ifa_addr;

        if (!ifa_addr)
            continue ;
        else if (addr_in.s_addr == ifa_addr->sin_addr.s_addr)
        {
            if (flag)
                printf("Interface trouvée: %s\n", ifa->ifa_name);
            return TRUE;
        }
    }
    return FALSE;
}

static bool_t valid_mac_address(char* mac_address, struct ifaddrs* ifa_head)
{
    unsigned char*  sll_mac_addr;

    sll_mac_addr = mac_str_to_sll(mac_address);
    if (!sll_mac_addr)
        return FALSE;
    for (struct ifaddrs *ifa = ifa_head; ifa != NULL; ifa = ifa->ifa_next)
    {
        struct sockaddr_ll* ifa_addr = (struct sockaddr_ll*)ifa->ifa_addr;

        if (!ifa_addr)
            continue ;
        else if (!ft_strncmp(ifa_addr->sll_addr, sll_mac_addr, 6))
        {
            free(sll_mac_addr);
            return TRUE;
        }
    }
    free(sll_mac_addr);
    return FALSE;
}

static unsigned char* mac_str_to_sll(char *mac_addr)
{
    char**         octets;
    unsigned char* sll_addr;   
    
    sll_addr = malloc(sizeof(char) * 8);
    if (!sll_addr)
        return NULL;
    octets = ft_split(mac_addr, ':');
    if (!octets)
    {
        free(sll_addr);
        return NULL;
    }
    for (ssize_t i = 0; i < 6; i++)
    {
        if (ft_strlen(octets[i]) != 2)
        {
            free(sll_addr);
            ft_free_tab((void**)octets);
            return NULL;
        }
        sll_addr[i] = parse_byte(octets[i]);
        if (sll_addr[i] == 0)
        {
            free(sll_addr);
            ft_free_tab((void**)octets);
            return NULL;
        }
    }
    ft_free_tab((void**)octets);
    return sll_addr;
}

static int hex_char_to_value(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return -1;
}

static unsigned char parse_byte(char* str)
{
    int high = hex_char_to_value(str[0]);
    int low =  hex_char_to_value(str[1]);

    if (high == -1 || low == -1)
        return 0;

    return (high << 4) | low;
}