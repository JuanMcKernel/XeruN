#include <base/system.h>
#include <engine/kernel.h>
#include <map>
#include <string>

class CKernel : public IKernel
{
	std::map<std::string, IInterface*> m_mpInterfaces;

public:

	CKernel()
	{ }


	virtual bool RegisterInterfaceImpl(const char *pName, IInterface *pInterface)
	{
		// TODO: More error checks here
		if(!pInterface)
		{
			dbg_msg("kernel", "ERROR: couldn't register interface %s. null pointer given", pName);
			return false;
		}

		if(m_mpInterfaces.find(pName) != m_mpInterfaces.end())
		{
			dbg_msg("kernel", "ERROR: couldn't register interface '%s'. interface already exists", pName);
			return false;
		}

		pInterface->m_pKernel = this;
		m_mpInterfaces.insert(std::pair<std::string, IInterface*>(pName, pInterface));

		return true;
	}


	virtual IInterface *RequestInterfaceImpl(const char *pName)
	{
		std::map<std::string, IInterface*>::iterator itItem = m_mpInterfaces.find(pName);
		if(itItem == m_mpInterfaces.end())
		{
			dbg_msg("kernel", "failed to find interface with the name '%s'", pName);
			return 0;
		}
		return itItem->second;
	}
};

IKernel *IKernel::Create() { return new CKernel; }
