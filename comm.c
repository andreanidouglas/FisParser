#include "comm.h"

void die(char *s)
{
    perror(s);
    exit(1);
}

unsigned char* dataSerializable(message m)
{
    unsigned char* data;
    data = (unsigned char*)malloc(sizeof(m));
    memcpy(data, &m, sizeof(m));
    return data;
}

message dataUnserialize(unsigned char* m)
{
    message data;
    long messageNum=0,
         timeStamp=0;
    int  i=0,
         ttl=0;
    char message[MESSAGE_SIZE];


    //unmarsh long
    for(i=sizeof(long)-1;i>=0;i--)
    {
        messageNum += m[i] * pow(256, i);
        timeStamp  += m[(i+sizeof(long))] * pow(256, i);
    }
    data.messageNum = messageNum;
    data.timeStamp = timeStamp;
    
    //unmarsh int
    for(i=sizeof(int)-1;i>=0;i--)
    {
        ttl += m[i+2*sizeof(long)] * pow(256,i);
    }
    data.ttl = ttl;
    
    //unmarsh char[]
    for (i=0; i<MESSAGE_SIZE;i++)
    {
        message[i] = m[i+(2*sizeof(long)+sizeof(int))];
    }
    strcpy(data.message, message);
    return data;
}

int bind_client(struct sockaddr_in* si_me, struct sockaddr_in* si_other)
{
    int bind_descritor=0;

    si_me = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));
    si_other = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));
    memset((char *) si_other, 0, sizeof(*si_other));
    si_other->sin_family = AF_INET;
    si_other->sin_port = htons(PORT);
    if((bind_descritor=inet_aton(SERVER, &(si_other->sin_addr)))==0)
    {
        die("bind()");
    }
    return bind_descritor;
}

int bind_server(int* socket_descritor, struct sockaddr_in* si_me, struct sockaddr_in* si_other)
{
    int bind_descritor=-1;

    si_me = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));
    si_other = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));
    memset((char*)si_me, 0, sizeof(*si_me));
    si_me->sin_family = AF_INET;
    si_me->sin_port = PORT;
    si_me->sin_addr.s_addr = htonl(INADDR_ANY);
    if ((bind_descritor=bind(*socket_descritor, (struct sockaddr*) si_me, sizeof(*si_me)))==-1)
    {
        die("bind()");
    }
    return bind_descritor;
}

void socket_handler(int* socket_descritor, int* bind_descritor, struct sockaddr_in* si_me, struct sockaddr_in* si_other, int OP, char* buffer)
{
    if (socket_descritor == NULL)
    {
        socket_descritor = (int*)malloc(sizeof(int));
        if((*socket_descritor=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
        {
            die("socket()");
        }
    }

    if (bind_descritor == NULL)
    {
        bind_descritor = (int*)malloc(sizeof(int));
        switch(OP)
        {
            case 1:
                *bind_descritor = bind_server(socket_descritor, si_me, si_other);
                break;
            case 2:
                *bind_descritor = bind_client(si_me, si_other);
                break;
            default:
            die("Operation not defined");
        }
        if (*bind_descritor == -1 || *bind_descritor == 0)
        {
            die("bind()");
        }
    }
}


int main(int argc, char **argv) 
{
    int* socket=NULL;
    int* bind=NULL;
    struct sockaddr_in* si_me=NULL;
    struct sockaddr_in* si_other=NULL;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);
    socket_handler(socket, bind, si_me, si_other, RECEIVE, buffer);

    return (0);
}
