/* See LICENSE file for copyright and license details. */


/**
 * Bind a unix(7) socket to a random file name in a specific directory
 * 
 * @param   fd           The socket's file descriptor
 * @param   dir_fd       File descriptor to the directory the socket shall be
 *                       stored in (may be `AT_FDCWD`)
 * @param   addr_out     Output parameter for the socket name (may be `NULL`);
 *                       `&strrchr(addr_out->sun_path, '/')[1]` will be the
 *                       name of the file the socket will be bound to
 * @param   addrlen_out  Output parameter for the size of the socket name (may be `NULL`)
 * @return               0 on success, -1 on failure
 * 
 * @since  1.6
 */
int libsimple_bindtemp_un(int fd, int dir_fd, struct sockaddr_un *addr_out, socklen_t *addrlen_out); /* TODO man */
