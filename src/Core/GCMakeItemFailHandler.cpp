//////////////////////////////////////////////////////////////////////
//
// Filename    : GCMakeItemFailHandler.cc
// Written By  : elca@ewestsoft.com
// Description :
//
//////////////////////////////////////////////////////////////////////

// include files
#include "GCMakeItemFail.h"

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void GCMakeItemFailHandler::execute (GCMakeItemFail * pGCMakeItemFail , Player * pPlayer )
	 throw(Error )
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#ifdef __GAME_CLIENT__

	//cout << pGCMakeItemFail->toString() << endl;
	
#elif __WINDOWS__

#endif

	__END_DEBUG_EX __END_CATCH
}
