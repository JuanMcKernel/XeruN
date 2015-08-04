#include "gameclient.h"
#include <engine/client.h>

CGameClient g_GameClient;

IGameClient *CreateGameClient()
{
	return &g_GameClient;
}

void CGameClient::OnInit()
{
	dbg_msg("INIT", "Entorno Iniciado!");
}

void CGameClient::OnRender()
{

}
