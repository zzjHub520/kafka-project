#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h> 
#include <sys/types.h>
#include<sys/wait.h>

#define SUB_PROCESS_NUM 5   //定义生成三个子进程
#define MAX_BUFFER_SIZE 255

#define START_PROT 8500

int createSocket(int* sockfd, sockaddr_in& addr, int processIndex) {
    // 建立不可靠单向派送。
    if ((*sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        return -1;
    }
    int len = sizeof(addr);
    bzero(&addr, len);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(START_PROT + processIndex);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(*sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cerr << "catch error when connect socket. " << errno << std::endl;
        close(*sockfd);
        return -1;
    }
    // udp dont need to listen
    // if (listen(*sockfd, 5) < 0) {
    //     std::cerr << "catch error when starting listen. " << std::endl;
    //     close(*sockfd);
    //     return -1;
    // }
    std::cout << "create socket success send on port " << START_PROT+processIndex << std::endl;
    return 1;
}

int main() {
    pid_t pid;
    int index = 0;
    for (int i = 0; i < SUB_PROCESS_NUM; i++) {
        index = i;  //index会继承给子进程
        pid = fork();
        if (pid == 0 || pid == -1) break; 
    }
    // 子进程派送消息，主进程等待
    if (pid == 0) {
        int status, sockid;
        sockaddr_in sockInfo;
        status = createSocket(&sockid, sockInfo, index);
        if (status == 1) {
            int counter = 0;
            // create buffer
            char buffer[MAX_BUFFER_SIZE];
            while (counter < 10) {
                // 休眠5秒内随机时长，发送一条数据
                auto sleepTime = random() % 10;
                sleep(sleepTime);
                // 准备发送的消息。
                sprintf(buffer, "I am sub process, %d, ijust sleep %ld", index, sleepTime);
                std::cout <<buffer<<std::endl;
                send(sockid, buffer, strlen(buffer), 0);
                counter++;
            }
            close(sockid);
            exit(0);
        }
    } else if(pid > 0){
        waitpid(-1, NULL, 0);
        exit(0);
    }
}