#include "../includes/include.h" 

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        printf("Error: Wrong amount of arguments\nTry something like: ./ft_malcolm <source ip> <source mac address> <target ip> <target mac address>");
        return 1;
    }

    if (valid_ip_address(argv[1]))
        printf("HEY cestbon");
    return 0;
}