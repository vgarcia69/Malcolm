#include "../includes/include.h"

bool_t wait_request_and_reply()
{
	int 				fd_socket;
    ssize_t 			byte_read;
	socklen_t			addr_len;
	unsigned char 		buffer[2048];
	struct sockaddr 	addr_source;

    fd_socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    if (fd_socket == -1)
    {
        printf("ft_malcolm: Try with root access\n");
        return FALSE;
    }
	addr_len = sizeof(addr_source);
	ft_memset(&addr_source, 0, addr_len);

	byte_read = recvfrom(fd_socket, buffer, 2048, 0, &addr_source, &addr_len);
	if (byte_read < 0)
		return FALSE;
	printf("An ARP request has been broadcast.\n");
	printf("	mac address of request: %02X:%02X:%02X:%02X:%02X:%02X\n",
		buffer[22],
		buffer[23],
		buffer[24],
		buffer[25],
		buffer[26],
		buffer[27]
	);
	printf("	ip address of request: %d.%d.%d.%d\n",
		buffer[28],
		buffer[29],
		buffer[30],
		buffer[31]
	);
    printf("Now sending an ARP reply to the target address with spoofed source, please wait...\n");

	send_reply(&fd_socket, buffer, &addr_source, addr_len);

    printf("Sent an ARP reply packet, you may now check the arp table on the target.\n");
    printf("Exiting program...\n");
	return TRUE;
}

bool_t send_reply(int* fd_socket, unsigned char* buffer, struct sockaddr_sll* addr_source, socklen_t addr_len)
{
	unsigned char packet[2048];

	build_packet(addr_source, addr_len);

	sendto(*fd_socket, packet, sizeof(buffer), 0, addr_source, addr_len);
	close(*fd_socket);
	return TRUE;
}