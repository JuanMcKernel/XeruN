/*
 * gamecore.h
 *
 *  Created on: 4/8/2015
 *      Author: uchar
 */

#ifndef SRC_GAME_GAMECORE_H_
#define SRC_GAME_GAMECORE_H_

#include <engine/shared/netsettings.h>
#include <SFML/Graphics.hpp>

class CWorldCore
{
public:
	class CCharacterCore *m_apCharacterCore[MAX_CLIENTS];
};

class CCharacterCore
{
	CWorldCore *m_pWorldCore;

public:
	sf::Vector2f m_Pos;

	void Init(CWorldCore *pWorld);
};


#endif /* SRC_GAME_GAMECORE_H_ */
