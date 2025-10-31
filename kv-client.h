#ifndef KV-CLIENT_H
#define KV-CLIENT_H

#define SOCKET_PATH "/tmp/kvstore.sock"
#define BUF_SIZE 1024

int send_command(const char *command);

#endif
