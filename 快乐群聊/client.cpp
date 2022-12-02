#windows 客户端
#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#define server_ip "xxx.xx.xx.xxx"
#define server_port xxxx
#include"client.hpp"
int main() {
	//1.����˭
	string name=authentication();
	//2.��ȡʱ��
	cout << get_comp_time();
	//3.���ӷ�����
	//3.1��udp���� ȷ�Ϸ�������ַ:�˿�
	string local_ip(getlocalip());
	cout << local_ip.c_str() << endl;
	udp_client_t client(server_ip,server_port,local_ip.c_str());
	//3.2���ӷ����� ��ʼ����
	client.run(name);



	

	return 0;
}