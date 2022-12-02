//Linux 服务器
#include "server.hpp"
void usage()
{
    cout << "usage::./server.out port" << endl;
}
int main(int argc, char *argv[])
{
    //确认参数
    if (argc != 2)
    {
        usage();
        exit(1);
    }
    //初始化服务器
    server_t server(atoi(argv[1]));
    //提供服务
    server.run();
    return 0;
}