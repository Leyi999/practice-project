#include <iostream>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define buffer_size 4096
using namespace std;
/// @leyi
//服务器对象
class server_t
{
public:
    //不提供默认构造,服务端采用ip:addr_any +  指定port
    server_t(const uint32_t port_num)
    {
        //初始化成员
        bzero(_buffer, buffer_size);
        uint32_t ip = INADDR_ANY;
        uint16_t port = htons(port_num);
        // socket
        _socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
        if (_socket_fd == -1)
        {
            cerr << "socket_error!" << endl;
            exit(2);
        }
        //填充信息
        _host.sin_family = AF_INET;
        _host.sin_addr.s_addr = ip;
        _host.sin_port = port;
        //通过bind 填入内核
        int bind_ret = bind(_socket_fd, (const sockaddr*)&_host, sizeof(_host));
        if (bind_ret == -1)
        {
            cerr << "bind_error!" << endl;
            exit(3);
        }
    }
    // RUN...
    void run()
    {
        //远端信息
        sockaddr_in peer;
        // peer_len
        socklen_t len = sizeof(peer);
        while (1)
        {
            bzero(&peer, 0);
            len = sizeof(peer);
            if (recvfrom(_socket_fd, _buffer, buffer_size - 1, 0, (struct sockaddr*)&peer, &len) > 0)
            {
                //保存客户端消息
                string key_str(to_string(peer.sin_addr.s_addr) + string(":") + to_string(ntohs(peer.sin_port)));
                _clients[key_str] = peer;
                //可通过重定向在服务器 再服务器保存聊天记录(我没有这样做)
                cout << _buffer;
                cout.flush();
                //将消息广播式转发回客户端
                send();
            }
        }
    }

private:
    //广播消息
    void send()
    {
        for (auto& e : _clients)
        {
            if (sendto(_socket_fd, _buffer, strlen(_buffer) + 1, 0, (sockaddr*)&(e.second), sizeof(e.second)) == -1)
                _clients.erase(e.first);
        }
    }

private:
    //消息缓冲区
    char _buffer[buffer_size];
    //socket内存级文件描述符fd
    int _socket_fd;
    //主机信息
    sockaddr_in _host;
    //用 pair<"ip:port",sockaddr_in>来描述客户端
    unordered_map<string, sockaddr_in> _clients;
};