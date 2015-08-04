/*
 * client.h
 *
 *  Created on: 4/8/2015
 *      Author: uchar
 */

#ifndef SRC_ENGINE_CLIENT_CLIENT_H_
#define SRC_ENGINE_CLIENT_CLIENT_H_

#include <engine/client.h>

class CClient : public IClient
{
public:
	CClient();

	void Init();
	void Run();
};



#endif /* SRC_ENGINE_CLIENT_CLIENT_H_ */
