//////////////////////////////////////////////////////////////////////
//
// Filename    : GCSkillFailed2Handler.cc
// Written By  : elca@ewestsoft.com
// Description :
//
//////////////////////////////////////////////////////////////////////

// include files
#include "GCSkillFailed2.h"

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void GCSkillFailed2Handler::execute (GCSkillFailed2 * pGCSkillFailed2 , Player * pPlayer )
	 throw(Error )
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#if __TEST_CLIENT__

	//cout << pGCSkillFailed2->toString() << endl;
	
#elif __WINDOWS__

#endif

	__END_DEBUG_EX __END_CATCH
}
