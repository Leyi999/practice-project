//Linux ������
#include "server.hpp"
void usage()
{
    cout << "usage::./server.out port" << endl;
}
int main(int argc, char *argv[])
{
    //ȷ�ϲ���
    if (argc != 2)
    {
        usage();
        exit(1);
    }
    //��ʼ��������
    server_t server(atoi(argv[1]));
    //�ṩ����
    server.run();
    return 0;
}