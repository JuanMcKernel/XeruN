#include "server.h"
#include <engine/shared/netsettings.h>
#include <base/system.h>
#include <cstdlib>


SServer::SServer()
{

}

void SServer::Init()
{
    if (m_socket.bind(PORT) != sf::Socket::Done)
        dbg_msg("Server", "ERROR: Couldn't listen port %d.", PORT);
    else dbg_msg("Server", "Listening port %d.", PORT);
}

void SServer::Run()
{

}

/*
 * MAIN
 */

int main()
{
	SServer *pServer = new SServer;
	IKernel *pKernel = IKernel::Create();
	pKernel->RegisterInterface(pServer);

	pServer->Init();
	pServer->Run();

	exit(EXIT_SUCCESS);
}
