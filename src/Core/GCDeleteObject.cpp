//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCDeleteObject.cpp 
// Written By  : Reiot
// Description : 
// 
//////////////////////////////////////////////////////////////////////

// include files
#include "GCDeleteObject.h"

//////////////////////////////////////////////////////////////////////
// �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////
void GCDeleteObject::read (SocketInputStream & iStream ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY

	iStream.read(m_ObjectID);

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
//////////////////////////////////////////////////////////////////////
void GCDeleteObject::write (SocketOutputStream & oStream ) const 
     throw(ProtocolException , Error )
{
	__BEGIN_TRY

	oStream.write(m_ObjectID);

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// execute packet's handler
//////////////////////////////////////////////////////////////////////
void GCDeleteObject::execute (Player * pPlayer ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCDeleteObjectHandler::execute (this , pPlayer);
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// get debug string
//////////////////////////////////////////////////////////////////////
string GCDeleteObject::toString () const
	throw()
{
	StringStream msg;
	msg << "GCDeleteObject("
		<< "ObjectID:" << m_ObjectID
		<< ")";
	return msg.toString();
}
