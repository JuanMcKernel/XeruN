#ifndef SRC_ENGINE_SERVER_H_
#define SRC_ENGINE_SERVER_H_
#include "kernel.h"
#include <SFML/Graphics.hpp>

class IServer : public IInterface
{
	MACRO_INTERFACE("server")

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

#endif /* SRC_ENGINE_SERVER_H_ */
