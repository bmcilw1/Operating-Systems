#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

int main(int argc, char *argv[]) {

    int    sockfd = 0, n = 0;
    char   recvBuff[256];
    char   inputBuff[256] = " \0";
    char   cmdBuff[256] = " \0";
    struct sockaddr_in serv_addr; 

    if (argc != 2) {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    } 

    memset(recvBuff, '0',sizeof(recvBuff));

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000); 

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0) {
        printf("\n inet_pton error occured\n");
        return 1;
    } 

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
       printf("\n Error : Connect Failed \n");
       return 1;
    } 

    while(read(STDIN_FILENO, inputBuff, strlen(inputBuff))) {
        strcat(cmdBuff, inputBuff);
        printf("inputBuff: %s\n", inputBuff);

        // Execute when the client hits enter
        if (strcmp(inputBuff, "\n") == 0) {
            printf("cmdBuff: %s\n", cmdBuff);

            if (send(sockfd, cmdBuff, sizeof(cmdBuff), 0) < 0) {
               printf("\n Error : Send Command Failed \n");
               return 1;
            } 

            while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0) {
                printf("recvBuff: %s\n", recvBuff);

                recvBuff[n] = 0;

                printf("post recvBuff[n] = 0: %s\n", recvBuff);

                if(fputs(recvBuff, stdout) == EOF) 
                    printf("\n Error : Fputs error\n");

                if (n < 0)
                    printf("\n Read error \n");
            } 

            // Clear the buffers
            memset(cmdBuff, '0', sizeof(cmdBuff));
            memset(recvBuff,'0', sizeof(recvBuff));
            fflush(stdout);

            printf("post loop inputBuff: %s\n", inputBuff);
        }
    }

    close(sockfd);

    return 0;
}
