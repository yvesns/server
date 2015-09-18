//////////////////////////////////////////////////////////////////////
// 
// Filename    : LCRegisterPlayerError.h 
// Written By  : Reiot
// Description :
// 
//////////////////////////////////////////////////////////////////////

#ifndef __LC_REGISTER_PLAYER_ERROR_H__
#define __LC_REGISTER_PLAYER_ERROR_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class LCRegisterPlayerError;
//
//////////////////////////////////////////////////////////////////////

class LCRegisterPlayerError : public Packet {

public:
	LCRegisterPlayerError() {};
    ~LCRegisterPlayerError() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_LC_REGISTER_PLAYER_ERROR; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() { return szBYTE; }
	
	// get packet's name
	string getPacketName() const throw() { return "LCRegisterPlayerError"; }
	
	// get packet's debug string
	string toString() const throw();
	
	BYTE getErrorID() const throw() { return m_ErrorID; }
	void setErrorID(BYTE ErrorID) throw() { m_ErrorID = ErrorID; }

private : 

	// ���� ID
	BYTE m_ErrorID;

};


//////////////////////////////////////////////////////////////////////
//
// class LCRegisterPlayerErrorFactory;
//
// Factory for LCRegisterPlayerError
//
//////////////////////////////////////////////////////////////////////

class LCRegisterPlayerErrorFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket() throw() { return new LCRegisterPlayerError(); }

	// get packet name
	string getPacketName() const throw() { return "LCRegisterPlayerError"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_LC_REGISTER_PLAYER_ERROR; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize() const throw() { return szBYTE; }
	
};


//////////////////////////////////////////////////////////////////////
//
// class LCRegisterPlayerErrorHandler;
//
//////////////////////////////////////////////////////////////////////

class LCRegisterPlayerErrorHandler {

public:

	// execute packet's handler
	static void execute(LCRegisterPlayerError* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};

#endif