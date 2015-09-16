//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCFlagWarStatus.cpp 
// Written By  : elca@ewestsoft.com
// Description : 자신에게 쓰는 기술의 성공을 알리기 위한 패킷 클래스의
//               멤버 정의.
// 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// include files
//////////////////////////////////////////////////////////////////////
#include "GCFlagWarStatus.h"



//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
GCFlagWarStatus::GCFlagWarStatus () 
     throw()
{
	__BEGIN_TRY
	__END_CATCH
}

	
//////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////
GCFlagWarStatus::~GCFlagWarStatus () 
    throw()
{
	__BEGIN_TRY
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
//////////////////////////////////////////////////////////////////////
void GCFlagWarStatus::read (SocketInputStream & iStream ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	iStream.read(m_TimeRemain);
	iStream.read(m_FlagCount[0]);
	iStream.read(m_FlagCount[1]);
	iStream.read(m_FlagCount[2]);

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
//////////////////////////////////////////////////////////////////////
void GCFlagWarStatus::write (SocketOutputStream & oStream ) 
     const throw(ProtocolException , Error )
{
	__BEGIN_TRY

	oStream.write(m_TimeRemain);
	oStream.write(m_FlagCount[0]);
	oStream.write(m_FlagCount[1]);
	oStream.write(m_FlagCount[2]);
		
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
//
// execute packet's handler
//
//////////////////////////////////////////////////////////////////////
void GCFlagWarStatus::execute (Player * pPlayer ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCFlagWarStatusHandler::execute(this , pPlayer);
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// get packet's debug string
//
//////////////////////////////////////////////////////////////////////
string GCFlagWarStatus::toString () 
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCFlagWarStatus("
		<< ")";
	return msg.toString();

	__END_CATCH
}

