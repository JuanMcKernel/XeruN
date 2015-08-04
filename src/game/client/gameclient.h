/*
 * gameclient.h
 *
 *  Created on: 4/8/2015
 *      Author: uchar
 */

#ifndef SRC_GAME_CLIENT_GAMECLIENT_H_
#define SRC_GAME_CLIENT_GAMECLIENT_H_

#include <engine/kernel.h>
#include <engine/client.h>

class CGameClient : public IGameClient
{
public:
	IKernel *Kernel() { return IInterface::Kernel(); }

	virtual void OnInit();
	virtual void OnRender();
};



#endif /* SRC_GAME_CLIENT_GAMECLIENT_H_ */
