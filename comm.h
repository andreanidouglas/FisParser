//Std Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Network Libraries
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

//Other Libraries
#include <math.h>

//Program Definitions
#define SERVER "127.0.0.1"
#define PORT 8888
#define BUFFER_SIZE 1024
#define MESSAGE_SIZE 10
#define INITIALIZE_COMM "CONNECT"
#define ACK "ACK"
#define SEND 1
#define RECEIVE 2

//Other Definitions
#define DEBUG 1

//Types
typedef struct _message {
    long messageNum;
    long timeStamp;
    int ttl;
    char message[MESSAGE_SIZE];
} message;

