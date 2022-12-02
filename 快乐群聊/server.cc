#include "server.hpp"
void usage()
{
    cout << "usage::./server.out port" << endl;
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        usage();
        exit(1);
    }
    server_t server(atoi(argv[1]));
    server.run();
    return 0;
}