#include "../includes/include.h"

bool_t wait_request(int* fd_socket, unsigned char buffer[2048])
{
	struct sockaddr  addr_source;
	socklen_t			addr_len;
    ssize_t 			byte_read;

    *fd_socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    if (*fd_socket == -1)
    {
        printf("ft_malcolm: Try with root access\n");
        return FALSE;
    }
	addr_len = sizeof(addr_source);
	ft_memset(&addr_source, 0, addr_len);

	byte_read = recvfrom(*fd_socket, buffer, 2048, 0, &addr_source, &addr_len);
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
	// enfaite faut construire un nouveau packet 
	sendto(*fd_socket, buffer, 2048, 0, &addr_source, addr_len);
	close(*fd_socket);
	return TRUE;
}

bool_t send_reply(int* fd_socket, unsigned char* buffer)
{
	// sendto(*fd_socket, buffer, sizeof(buffer), 0, NULL, 0);
	// close(*fd_socket);
	(void)*fd_socket; (void)*buffer;
	return TRUE;
}