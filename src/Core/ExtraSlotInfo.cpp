//////////////////////////////////////////////////////////////////////////////
// Filename    : ExtraSlotInfo.cpp
// Written By  : elca
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "ExtraSlotInfo.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
ExtraSlotInfo::ExtraSlotInfo()
{
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
ExtraSlotInfo::~ExtraSlotInfo()
    throw()
{
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void ExtraSlotInfo::read (SocketInputStream & iStream ) 
	throw(ProtocolException , Error )
{
	__BEGIN_TRY

	PCItemInfo::read(iStream);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void ExtraSlotInfo::write (SocketOutputStream & oStream ) const 
	throw(ProtocolException , Error )
{
	__BEGIN_TRY

	PCItemInfo::write(oStream);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// get debug string
//////////////////////////////////////////////////////////////////////////////
string ExtraSlotInfo::toString () const 
	throw()
{
	return PCItemInfo::toString();
}