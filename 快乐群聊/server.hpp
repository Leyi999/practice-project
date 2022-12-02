#include <iostream>
#include <thread>
#include <mutex>
#include <map>
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define buffer_size 4096
using namespace std;
bool operator<(const sockaddr_in &a, const sockaddr_in &b)
{
    return a.sin_addr.s_addr - a.sin_port < b.sin_addr.s_addr - b.sin_port;
}
bool operator==(const sockaddr_in &a, const sockaddr_in &b)
{
    return a.sin_addr.s_addr == b.sin_addr.s_addr && a.sin_port == b.sin_port;
}
bool operator>(const sockaddr_in &a, const sockaddr_in &b)
{
    return a.sin_addr.s_addr - a.sin_port > b.sin_addr.s_addr - b.sin_port;
}
struct sock_cmp
{
    bool operator()(const sockaddr_in &a, const sockaddr_in &b)
    {
        return a.sin_addr.s_addr < b.sin_addr.s_addr;
    }
};
class server_t
{
public:
    server_t(const uint32_t port_num)
    {
        bzero(_buffer, buffer_size);
        uint32_t ip = INADDR_ANY;
        uint16_t port = htons(port_num);
        _socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
        if (_socket_fd == -1)
        {
            cerr << "socket_error!" << endl;
            exit(2);
        }
        _host.sin_family = AF_INET;
        _host.sin_addr.s_addr = ip;
        _host.sin_port = port;
        int bind_ret = bind(_socket_fd, (const sockaddr *)&_host, sizeof(_host));
        if (bind_ret == -1)
        {
            cerr << "bind_error!" << endl;
            exit(3);
        }
    }
    void send()
    {
        for (auto &e : _clients)
        {
            if (sendto(_socket_fd, _buffer, strlen(_buffer) + 1, 0, (sockaddr *)&(e.second), sizeof(e.second)) == -1)
                _clients.erase(e.first);
        }
    }
    void run()
    {
        sockaddr_in peer;
        socklen_t len = sizeof(peer);
        while (1)
        {
            bzero(&peer, 0);
            len = sizeof(peer);
            if (recvfrom(_socket_fd, _buffer, buffer_size - 1, 0, (struct sockaddr *)&peer, &len) > 0)
            {
                _clients[peer.sin_port] = peer;
                cout << _buffer;
                cout.flush();
                send();
            }
        }
    }

private:
    char _buffer[buffer_size];
    int _socket_fd;
    sockaddr_in _host;
    map<uint16_t, sockaddr_in> _clients;
};