#include "client.h"
#include <cstdlib>

CClient::CClient()
{
	m_pWindow = nullptr;
	m_pGameClient = nullptr;
}
CClient::~CClient()
{
	delete m_pWindow;
}


void CClient::Init()
{
	m_pGameClient = Kernel()->RequestInterface<IGameClient>();

	m_pWindow = new sf::RenderWindow(sf::VideoMode(IClient::SCREEN_W, IClient::SCREEN_H), "XeruN v0.0.1");
	m_MainView = m_pWindow->getDefaultView();
	m_MainView.setSize(IClient::SCREEN_W, IClient::SCREEN_H);
	m_MainView.setCenter(IClient::SCREEN_W/2, IClient::SCREEN_H/2);
	m_pWindow->setView(m_MainView);
}

void CClient::Run()
{
	GameClient()->OnInit();

	while (m_pWindow && m_pWindow->isOpen())
	{
		sf::Event event;
		while (m_pWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_pWindow->close();
		}

		m_pWindow->clear();
			GameClient()->OnRender();
		m_pWindow->display();
	}
}


/*
 * MAIN
 */

int main()
{
	CClient *pClient = new CClient;
	IKernel *pKernel = IKernel::Create();

	pKernel->RegisterInterface(pClient);
	pKernel->RegisterInterface(CreateGameClient());

	pClient->Init();
	pClient->Run();

	exit(EXIT_SUCCESS);
}
