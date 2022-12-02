#pragma once
#pragma comment(lib, "ws2_32.lib")
#include<iostream>
#include<time.h>
#include<errno.h>
#include<string>
#include<fstream>
#include<thread>
#include<mutex>
#include <WinSock2.h>
#define buffer_size 4096
using namespace std;
string authentication() {
	string name(40,0);
	int sure_name = 0;
	while (!sure_name) {
		cout << "����˭:> ";
		cin >> name;
		(void)getchar();
		cout << "����[" << name << "]" << "��?" << endl;
		cout << "1.ȷ��             0.��������" << endl;
		cout << "������(1/0):> ";
		cin >> sure_name;
		(void)getchar();
		if (sure_name != 0 && sure_name != 1) {
			cout << "�������� ֻ������1/0!" << endl;
			exit(2);
		}
	}
	return name;
}
string get_time() {
	//time()
	//Wed Nov 30 13:44:19 2022
	time_t current_time = time(nullptr);
	string time_str(ctime(&current_time));
	//��ȡ��ʱ��
	int start = 0, end = 0;
	int count = 0;
	for (int i = 0; i < (int)time_str.size(); i++) {
		if (time_str[i] == ':') {
			start = i - 2;
			end = i + 6;
			break;

		}
	}
	return string(time_str.begin() + start, time_str.begin() + end);
}
void trimstring(std::string& str)
{
	if (!str.empty())
	{
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
	}
}

std::string getlocalip()
{
	std::string ip("");
	std::string ipconfig_content;

	FILE* fp = _popen("ipconfig", "r");
	if (NULL != fp)
	{
		char line[4096];
		while (NULL != fgets(line, sizeof(line), fp))
		{
			ipconfig_content += line;
		}

		auto p = ipconfig_content.rfind("IPv4");
		if (p != std::string::npos)
		{
			auto p2 = ipconfig_content.find(":", p);
			if (p2 != std::string::npos)
			{
				auto p3 = ipconfig_content.find("\n", p2);
				if (p3 != std::string::npos)
				{
					ip = ipconfig_content.substr(p2 + 1, p3 - p2 - 1);
					trimstring(ip);
				}
			}
		}
		_pclose(fp);
	}
	return ip;
}

string get_comp_time() {
	time_t current_time = time(nullptr);
	return 	string(ctime(&current_time));
}
void setxy(SHORT x, SHORT y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
COORD GetConsoleCursor() {
	COORD coordScreen = { 0, 0 }; //���λ��
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		coordScreen.X = csbi.dwCursorPosition.X;
		coordScreen.Y = csbi.dwCursorPosition.Y;
	}
	return coordScreen; //���λ��
}
class udp_client_t {
public:
	udp_client_t(const char* to_ip,u_short port,const char* local_ip=nullptr)
		:_cursor_mutex()
	{
		//ȷ����Ϣ
		_to_ip = inet_addr(to_ip);
		_to_port = htons(port);
		//�򿪲���
		WSADATA wsa_data;
		(void)WSAStartup(MAKEWORD(1, 1), &wsa_data);
		_socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
		if (_socket_fd == -1) {
			cerr << "socket error!" << endl;
			exit(1);
		}
		//�����Ϣ
		memset(&_local, 0, sizeof(_local));
		_local.sin_family = AF_INET;
		_local.sin_addr.s_addr = _to_ip;
		_local.sin_port = _to_port;
		//������
		sockaddr_in tmp;
		memset(&tmp, 0, sizeof(tmp));
		tmp.sin_addr.s_addr = local_ip ? inet_addr(local_ip): ADDR_ANY;
		tmp.sin_family = AF_INET;
		tmp.sin_port = htons(8083);
		int bind_ret=bind(_socket_fd, (sockaddr*)&tmp, sizeof(tmp));
		if (bind_ret) {
			cerr << "bind_error" << endl;
			exit(4);
		}
	}
	~udp_client_t() {
		closesocket(_socket_fd);
		WSACleanup();
	}
	void run(const string& name) {
		thread send_thread{ thread_send_routine,this,name };
		thread recv_thread{ thread_recive_routine,this, GetConsoleCursor() };
		thread keep_online{ thread_keep_online_routine,this };
		recv_thread.join();
		send_thread.join();
		keep_online.join();
	}
private:
	//��������
	static void thread_keep_online_routine(udp_client_t* _this) {
		const char* tmp = "";
		while (1) {
			sendto(_this->_socket_fd, tmp, 1, 0, (sockaddr*)&(_this->_local), sizeof(_this->_local));
			Sleep(3000);
		}
	}
	//������Ϣ
	static void thread_send_routine(udp_client_t*_this,const string& name) {
		//�������
		string buffer_str("");
		buffer_str.resize(buffer_size, 0);
		string time = get_time();
		string t_name=string()+" [" + name + "]" + ": ";
		int input_index = strlen(buffer_str.c_str());
		string tmp_str = time + t_name + string("������...\n");
		sendto(_this->_socket_fd, tmp_str.c_str(), strlen(tmp_str.c_str()) + 1, 0, (sockaddr*)&(_this->_local), sizeof(_this->_local));
		while (1) {
			//���ù��λ��
			_this->_cursor_mutex.lock();
			setxy(50, 0);
			cout << string(49, ' ') << endl;;
			setxy(50, 0);
			cout.flush();
			//��������
			cout << "������:> ";
			setxy(60, 0);
			_this->_cursor_mutex.unlock();
			time = get_time();
			fgets((char*)buffer_str.c_str()+input_index, buffer_size - 1, stdin);
			buffer_str = time + t_name + buffer_str;
			//��������
			sendto(_this->_socket_fd, buffer_str.c_str(), strlen(buffer_str.c_str()) + 1, 0, (sockaddr*)&(_this->_local), sizeof(_this->_local));
		}
	}
	static void thread_recive_routine(udp_client_t* _this,COORD start_pos) {
		//���ջ�����
		static int count = 0;
		char buffer[buffer_size];
		memset((void*)buffer, 0, buffer_size);
		auto cur_pos = start_pos;
		while (1) {
			int recv_ret=recvfrom(_this->_socket_fd,buffer,buffer_size-1,0,NULL,NULL);
			if (recv_ret > 0&&buffer[0]!='\0') {
				_this->_cursor_mutex.lock();
				auto back_pos = GetConsoleCursor();
				setxy(cur_pos.X, cur_pos.Y);
				if (count == 24) {
					system("cls");
					count = -6;
				}
				cout << buffer;
				count++;
				cur_pos = GetConsoleCursor();
				setxy(back_pos.X, back_pos.Y);
				_this->_cursor_mutex.unlock();
			}
			//WSAEINVAL;
		}
	}
private:
	//������ip
	u_int _to_ip;
	//�������˿�
	u_short _to_port;
	//����
	SOCKET _socket_fd;
	//�������׽���
	sockaddr_in _local;
	//�������λ�õĻ�����
	mutex _cursor_mutex;
};