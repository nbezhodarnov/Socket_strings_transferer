#include "server/server.h"

int main(int argc, char *argv[]) {
	// Чтение порта и ip-адреса IPv4 из командной строки
	char *ip;
	int port;
	bool unset_port = true, unset_ip = true;
	for (int i = 0; (i < argc) && (unset_ip || unset_port); i++) {
		if ((unset_port) && (isdigit(argv[i]))) {
			port = atoi(argv[i]);
			unset_port = false;
		}
		if ((unset_ip) && (ipcheck(argv[i]))) {
			ip = new char[strlen(argv[i])+1];
			strcpy(ip, argv[i]);
			unset_ip = false;
		}
	}
	if (unset_port) {
		port = 4234;
	}
	if (unset_ip) {
		ip = new char[11];
		strcpy(ip, "127.0.0.1");
	}
	
	// Запуск сервера
	Server server(port, ip);
	
	// Отправка и получение сообщений
	std::string message1;
	long long int message2;
	long double message3;
	server >> message1;
	std::cout << message1 << '\n';
	message1 = "Message from server!";
	server << message1;
	server >> message2;
	std::cout << message2 << '\n';
	message2 = 67890;
	server << message2;
	server >> message3;
	std::cout << message3 << '\n';
	message3 = 5.4;
	server << message3;
	
	delete []ip;
	return 0;
}
