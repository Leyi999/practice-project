//windows 客户端
#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#define server_ip "xxx.xx.xx.xxx"
#define server_port xxxx
#include"client.hpp"
int main() {
	//1.确认身份
	string name=authentication();
	//2.获取时间
	cout << get_comp_time();
	//3.初始化客户端
	string local_ip(getlocalip());
	cout << local_ip.c_str() << endl;
	udp_client_t client(server_ip,server_port,local_ip.c_str());
	//3 连接服务器
	client.run(name);



	

	return 0;
}