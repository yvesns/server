//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCRideMotorCycleFailed.cpp 
// Written By  : elca@ewestsoft.com
// Description : 자신에게 쓰는 기술의 성공을 알리기 위한 패킷 클래스의
//               멤버 정의.
// 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// include files
//////////////////////////////////////////////////////////////////////
#include "GCRideMotorCycleFailed.h"



//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
GCRideMotorCycleFailed::GCRideMotorCycleFailed () 
     throw()
{
	__BEGIN_TRY
	__END_CATCH
}

	
//////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////
GCRideMotorCycleFailed::~GCRideMotorCycleFailed () 
    throw()
{
	__BEGIN_TRY
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
//////////////////////////////////////////////////////////////////////
void GCRideMotorCycleFailed::read (SocketInputStream & iStream ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	// 최적화 작업시 실제 크기를 명시하도록 한다.
	iStream.read(m_ObjectID);

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
//////////////////////////////////////////////////////////////////////
void GCRideMotorCycleFailed::write (SocketOutputStream & oStream ) 
     const throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	// 최적화 작업시 실제 크기를 명시하도록 한다.
	oStream.write(m_ObjectID);

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// execute packet's handler
//
//////////////////////////////////////////////////////////////////////
void GCRideMotorCycleFailed::execute (Player * pPlayer ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCRideMotorCycleFailedHandler::execute(this , pPlayer);
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// get packet's debug string
//
//////////////////////////////////////////////////////////////////////
string GCRideMotorCycleFailed::toString () 
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCRideMotorCycleFailed("
		<< "ObjectID:" << (int)m_ObjectID 
		<< " )";
	return msg.toString();

	__END_CATCH
}
