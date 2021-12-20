#ifndef _SOCKET_SERVER_H_
#define _SOCKET_SERVER_H_
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h> 
#include <sys/types.h>
#include<sys/wait.h>
// shared_ptr
#include <memory>

#define SUB_PROCESS_NUM 5   //定义生成三个子进程
#define MAX_BUFFER_SIZE 255

#define START_PROT 8500

#define LISTEN_PORT {8500, 8501, 8502, 8503, 8504};

class My_socket_BASE {
public:
    enum SOCKET_TYPE {
        SCTP_SENDER,
        SCTP_RECIVER
    };
    //只能使用静态函数的方式创建
    static std::vector<std::shared_ptr<My_socket_BASE>> createLocalSockets(std::vector<int> ports, SOCKET_TYPE type);
    static std::shared_ptr<My_socket_BASE> createSingleSocket(int port, SOCKET_TYPE type);
    virtual ~My_socket_BASE() { close(m_nSocketId); };
    virtual int doMyJob() = 0;
    char* m_buffer;
protected:
    My_socket_BASE();
    virtual int createSocket() = 0;
    // int createSocketReciver(int* sockfd, sockaddr_in& addr, int processIndex);
    int m_nSocketId;
    sockaddr_in m_oAddrInfo;
};

class My_socket_sender : public My_socket_BASE {
public:
    virtual int doMyJob() override;
protected:
    My_socket_sender(int);
    virtual int createSocket() override;
};

class My_socket_receiver : public My_socket_BASE {
public:
    virtual int doMyJob() override;
// protected:
    My_socket_receiver(int);
    virtual int createSocket() override;
};
#endif