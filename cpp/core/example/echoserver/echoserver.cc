#include <iostream>
#include <utils/buffer.h>
#include <net/tcp_server.h>
#include <net/tcp_conn.h>

#pragma comment(lib, "libcore.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "libevent_core.lib")
#pragma comment(lib, "libevent_extras.lib")

void OnMessage(const TCPConnPtr& conn, Buffer* msg) {
	std::string s = msg->NextAllString();
	std::cout << "11 thread id:" << std::this_thread::get_id() << "Received a message [" << s << "]" << std::endl;
	conn->Send(s);

	if (s == "quit" || s == "exit") {
		conn->Close();
	}
}

void OnConnection(const TCPConnPtr& conn) {
	if (conn->IsConnected()) {
		std::cout << "11 thread id:" << std::this_thread::get_id() << std::endl;
		std::cout << "Accept a new connection from " << conn->remote_addr() << std::endl;
	}
	else {
		std::cout << "11 thread id:" << std::this_thread::get_id() << std::endl;
		std::cout << "Disconnected from " << conn->remote_addr() << std::endl;
	}
}

void OnMessage2(const TCPConnPtr& conn, Buffer* msg) {
	std::string s = msg->NextAllString();
	std::cout << "22 thread id:" << std::this_thread::get_id() << " Received a message [" << s << "]" << std::endl;
	conn->Send(s);

	if (s == "quit" || s == "exit") {
		conn->Close();
	}
}

void OnConnection2(const TCPConnPtr& conn) {
	if (conn->IsConnected()) {
		std::cout << "22 thread id:" << std::this_thread::get_id() << std::endl;
		std::cout << "22  Accept a new connection from " << conn->remote_addr() << std::endl;
	}
	else {
		std::cout << "22 thread id:" << std::this_thread::get_id() << std::endl;
		std::cout << "22 Disconnected from " << conn->remote_addr() << std::endl;
	}
}


int main(int argc, char* argv[]) {
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	std::string port = "9099";
	if (argc == 2) {
		port = argv[1];
	}
	std::string addr = std::string("0.0.0.0:") + port;
	EventLoop loop;
	TCPServer server(&loop, addr, "TCPEcho", 0);
	server.SetMessageCallback(&OnMessage);
	server.SetConnectionCallback(&OnConnection);
	server.Init();
	server.Start();

	TCPServer server2(&loop, std::string("0.0.0.0:9098"), "TCPEcho", 0);
	server2.SetMessageCallback(&OnMessage2);
	server2.SetConnectionCallback(&OnConnection2);
	server2.Init();
	server2.Start();

	loop.Run();

	WSACleanup();
	return 0;
}
