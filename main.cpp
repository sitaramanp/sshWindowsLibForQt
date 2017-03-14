
#ifndef SRCLIBSSH_H
#define SRCLIBSSH_H
extern "C"
{

#include <libssh/include/libssh/libssh.h>

int my_ssh_connect()
{
    ssh_session my_ssh_session;
    int rc;
    my_ssh_session = ssh_new();
    if (my_ssh_session == NULL)
        exit(-1);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "localhost");
    rc = ssh_connect(my_ssh_session);
    if (rc != SSH_OK)
    {
        exit(-1);
    }

    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);
    return 0;
}

}
#endif // SRCLIBSSH_H

int main(int argc, char *argv[])
{
    my_ssh_connect();
    return 0;
}
