#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include <sys/tyes.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT "3490"
#define BACKLOG 10

void sigchld_handler(int s)
{
    //waitpd() might overright errno, so we save it
    int saved_errno = errno;
    while(waitpd(-1, NULL, WHOHANG) > 0);
    errno = saved_errno;
}

void *get_in_addr(struct sockaddr *sa)
{
    if(sa->sa_family == AF_INET)
    {
        return &(((struct sockaddr_in)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6)sa)->sin6_addr);
}
int main(void)
{
    int sockfd, new_fd; //listen on sock_fd, new connections on new_fd
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr;//connector's addr
    socklen_t sin_size;
    struct sigaction sa;
    int yes=1;
    char s[INET6_ADDRSTRLEN];
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; //use my ip

    if(rv = getaddrinfo(NULL, PORT, &hints, &servinfo) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_stderr(rv));
        return 1;
    }

