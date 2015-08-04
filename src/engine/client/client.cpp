#include "client.h"
#include <cstdlib>

CClient::CClient()
{

}

void CClient::Init()
{

}

void CClient::Run()
{

}


/*
 * MAIN
 */

int main()
{
	CClient *pClient = new CClient;
	IKernel *pKernel = IKernel::Create();
	pKernel->RegisterInterface(pClient);
	//pClient->RegisterInterfaces();

	pClient->Init();
	pClient->Run();

	exit(EXIT_SUCCESS);
}
