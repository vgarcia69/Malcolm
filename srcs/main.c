#include "../includes/include.h" 

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        printf("ft_malcolm: Wrong amount of arguments\nTry something like: ./ft_malcolm <source ip> <source mac address> <target ip> <target mac address>");
        return 1;
    }
    struct ifaddrs* ifa_head;
    if (getifaddrs(&ifa_head) < 0)
    {
        printf("Internal error");
        return 1;
    }
    if (!valid_argument(argv, ifa_head))
    {
        freeifaddrs(ifa_head);
        return 1;
    }


    freeifaddrs(ifa_head);

    wait_request_and_reply();
    return 0;
}