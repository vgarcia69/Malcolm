#include "../includes/include.h"

bool_t wait_signal(int fd_socket)
{
	unsigned char 		buffer[2048];
	struct sockaddr_ll  addr_source;
	socklen_t			addr_len;
    ssize_t 			len;

 	len = recvfrom(fd_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr_source, &addr_len);


	return TRUE;
}