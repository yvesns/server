//////////////////////////////////////////////////////////////////////
// 
// SocketEncryptOutputStream.cpp
// 
// by Reiot
// 
//////////////////////////////////////////////////////////////////////

#include "SocketEncryptOutputStream.h"
#include "Assert1.h"

//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
SocketEncryptOutputStream::SocketEncryptOutputStream (Socket * sock , uint BufferLen ) 
	throw(Error )
: SocketOutputStream(sock, BufferLen)
{
	__BEGIN_TRY
	__END_CATCH
}

SocketEncryptOutputStream::~SocketEncryptOutputStream()
	throw(Error )
{
	__BEGIN_TRY
	__END_CATCH
}

