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
//����������
class server_t
{
public:
    //���ṩĬ�Ϲ���,����˲���ip:addr_any +  ָ��port
    server_t(const uint32_t port_num)
    {
        //��ʼ����Ա
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
        //�����Ϣ
        _host.sin_family = AF_INET;
        _host.sin_addr.s_addr = ip;
        _host.sin_port = port;
        //ͨ��bind �����ں�
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
        //Զ����Ϣ
        sockaddr_in peer;
        // peer_len
        socklen_t len = sizeof(peer);
        while (1)
        {
            bzero(&peer, 0);
            len = sizeof(peer);
            if (recvfrom(_socket_fd, _buffer, buffer_size - 1, 0, (struct sockaddr*)&peer, &len) > 0)
            {
                //����ͻ�����Ϣ
                string key_str(to_string(peer.sin_addr.s_addr) + string(":") + to_string(ntohs(peer.sin_port)));
                _clients[key_str] = peer;
                //��ͨ���ض����ڷ����� �ٷ��������������¼(��û��������)
                cout << _buffer;
                cout.flush();
                //����Ϣ�㲥ʽת���ؿͻ���
                send();
            }
        }
    }

private:
    //�㲥��Ϣ
    void send()
    {
        for (auto& e : _clients)
        {
            if (sendto(_socket_fd, _buffer, strlen(_buffer) + 1, 0, (sockaddr*)&(e.second), sizeof(e.second)) == -1)
                _clients.erase(e.first);
        }
    }

private:
    //��Ϣ������
    char _buffer[buffer_size];
    //socket�ڴ漶�ļ�������fd
    int _socket_fd;
    //������Ϣ
    sockaddr_in _host;
    //�� pair<"ip:port",sockaddr_in>�������ͻ���
    unordered_map<string, sockaddr_in> _clients;
};