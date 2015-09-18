//--------------------------------------------------------------------------------
// 
// Filename    : GCShopSellFail.cpp 
// Written By  : �輺��
// Description : �÷��̾ NPC���� ������ �ȷ��� �ߴµ�, � ������
//               �������� ��쿡�� �� ��Ŷ�� �÷��̾�� �����ش�.
// 
//--------------------------------------------------------------------------------

// include files
#include "GCShopSellFail.h"
#include "Assert1.h"


//--------------------------------------------------------------------
// constructor
//--------------------------------------------------------------------

GCShopSellFail::GCShopSellFail() 
	throw()
{
	__BEGIN_TRY 
	
	__END_CATCH;
}

//--------------------------------------------------------------------
// destructor
//--------------------------------------------------------------------
GCShopSellFail::~GCShopSellFail() 
	throw()
{
	__BEGIN_TRY 
	
	
	__END_CATCH;
}

//--------------------------------------------------------------------
// �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
//--------------------------------------------------------------------
void GCShopSellFail::read (SocketInputStream & iStream ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	//-----------------------------------------------------------------
	// read object id
	//-----------------------------------------------------------------
	iStream.read(m_ObjectID);

	__END_CATCH
}

		    
//--------------------------------------------------------------------------------
// ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
//--------------------------------------------------------------------------------
void GCShopSellFail::write (SocketOutputStream & oStream ) const 
     throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	//-----------------------------------------------------------------
	// write object id
	//-----------------------------------------------------------------
	oStream.write(m_ObjectID);

	__END_CATCH
}

//--------------------------------------------------------------------------------
// execute packet's handler
//--------------------------------------------------------------------------------
void GCShopSellFail::execute (Player * pPlayer ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCShopSellFailHandler::execute(this , pPlayer);

	__END_CATCH
}

//--------------------------------------------------------------------------------
// get packet's debug string
//--------------------------------------------------------------------------------
string GCShopSellFail::toString () const
       throw()
{
	__BEGIN_TRY
		
	StringStream msg;
	msg << "GCShopSellFail(" 
		<< "ObjectID:" << m_ObjectID
		<< ")";
	return msg.toString();
		
	__END_CATCH
}

