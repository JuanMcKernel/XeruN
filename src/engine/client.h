/*
 * client.h
 *
 *  Created on: 4/8/2015
 *      Author: uchar
 */

#ifndef SRC_ENGINE_CLIENT_H_
#define SRC_ENGINE_CLIENT_H_
#include "kernel.h"
#include <SFML/Graphics.hpp>

class IClient : public IInterface
{
	MACRO_INTERFACE("client")

public:
	enum
	{
		// TODO: Crear archivo de configuracion
		SCREEN_W = 800,
		SCREEN_H = 600,
	};

	sf::View m_MainView;
	sf::RenderWindow *m_pWindow;
};

class IGameClient : public IInterface
{
	MACRO_INTERFACE("gameclient")
public:

	virtual void OnInit() = 0;
	virtual void OnRender() = 0;
};
extern IGameClient *CreateGameClient();

#endif /* SRC_ENGINE_CLIENT_H_ */
