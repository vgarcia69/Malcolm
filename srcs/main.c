#include "../includes/include.h" 

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        printf("Error: Wrong amount of arguments\nTry something like: ./ft_malcolm <source ip> <source mac address> <target ip> <target mac address>");
        return 1;
    }

    if (valid_argument(argv))
    {
        return 1;
    }

    int fd_socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    if (fd_socket == -1)
    {
        printf("Error: Try with root access");
        return 1;
    }

    wait_event(fd_socket);

    close(fd_socket);
    return 0;
}