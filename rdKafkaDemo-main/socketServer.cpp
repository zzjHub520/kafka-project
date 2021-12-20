#include "socketServer.h"
#include <thread>

inline void doJobPerSec(My_socket_BASE* ptr) {
    if (!ptr) return;
    ptr->doMyJob();
}

My_socket_BASE::My_socket_BASE(){
    // m_nSocketId = 0;
    // int len = sizeof(m_oAddrInfo);
    // bzero(&m_oAddrInfo, len);
    // m_oAddrInfo.sin_family = AF_INET;
    // m_oAddrInfo.sin_addr.s_addr = inet_addr("127.0.0.1");
    // m_oAddrInfo.sin_port = htons(port);
    // if ((m_nSocketId = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    //     std::cerr << " error occur when create socket " << std::endl;
    // }
}

std::vector<std::shared_ptr<My_socket_BASE>> My_socket_BASE::createLocalSockets(std::vector<int> ports, SOCKET_TYPE type) {
    std::vector<std::shared_ptr<My_socket_BASE>> ret;
    for (auto port : ports) {
        ret.push_back(createSingleSocket(port, type));
    }
}

std::shared_ptr<My_socket_BASE> My_socket_BASE::createSingleSocket(int port, SOCKET_TYPE type) {
    if (type == SOCKET_TYPE::SCTP_SENDER) {
        //todo
        return nullptr;
    } else {
        // auto ptr = new My_socket_receiver(port);
        // return std::shared_ptr<My_socket_BASE>(ptr);
        return std::make_shared<My_socket_receiver>(port);
    }
}

int My_socket_sender::createSocket() {
    // 建立不可靠单向派送。
    if (connect(m_nSocketId, (struct sockaddr *)&m_oAddrInfo, sizeof(m_oAddrInfo)) < 0) {
        std::cerr << "catch error when connect socket. " << errno << std::endl;
        close(m_nSocketId);
        return -1;
    }
    std::cout << "create socket success send on port " << m_oAddrInfo.sin_port << std::endl;
    return 1;
}

My_socket_receiver::My_socket_receiver(int port) {
    m_nSocketId = 0;
    int len = sizeof(m_oAddrInfo);
    bzero(&m_oAddrInfo, len);
    m_oAddrInfo.sin_family = AF_INET;
    m_oAddrInfo.sin_addr.s_addr = inet_addr("127.0.0.1");
    m_oAddrInfo.sin_port = htons(port);
    if ((m_nSocketId = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << " error occur when create socket " << std::endl;
    }
    m_buffer = new char[255];
    createSocket();
}

int My_socket_receiver::doMyJob() {
    bzero(m_buffer, 255);
    struct sockaddr_in peeraddr;
    socklen_t peerlen;
    int n;
    
    peerlen = sizeof(peeraddr);
    n = recvfrom(m_nSocketId, m_buffer, 255, 0,
                    (struct sockaddr *)&peeraddr, &peerlen);
    if (n <= 0)
    {
        // std::cerr << "receive socket catch error " << errno << std::endl;
    }
    else if(n > 0)
    {
        printf("接收到的数据：%s\n",m_buffer);
    }
}

int My_socket_receiver::createSocket() {
    
    if (bind(m_nSocketId, (struct sockaddr *)&m_oAddrInfo, sizeof(m_oAddrInfo)) < 0) {
        std::cerr << "catch error when binding socket. " << errno << std::endl;
        close(m_nSocketId);
        return -1;
    }
    std::cout << "create socket Listen on port " << m_oAddrInfo.sin_port << std::endl;
    return 1;
}

// //test main
// int main () {
//     auto sock = std::move(My_socket_BASE::createSingleSocket(8500, My_socket_BASE::SOCKET_TYPE::SCTP_RECIVER));
//     if (sock) {
//         while (1) {
//             sleep(1);
//             doJobPerSec(sock.get());
//         }
//     }
//     return 0;
// }