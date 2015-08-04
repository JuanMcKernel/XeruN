#ifndef SRC_ENGINE_SERVER_SERVER_H
#define SRC_ENGINE_SERVER_SERVER_H

#include <SFML/Network.hpp>
#include <engine/server.h>

class SServer : public IServer
{
    sf::UdpSocket m_socket;

public:
	SServer();

	void Init();
	void Run();
};



#endif /* SRC_ENGINE_SERVER_SERVER_H_ */
