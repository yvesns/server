//////////////////////////////////////////////////////////////////////
// 
// Filename    : LCPCList.h 
// Written By  : Reiot
// Description :
// 
//////////////////////////////////////////////////////////////////////

#ifndef __LC_PC_LIST_H__
#define __LC_PC_LIST_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"
#include "PCInfo.h"
#include "PCSlayerInfo.h"
#include "PCVampireInfo.h"
#include "PCOustersInfo.h"

//////////////////////////////////////////////////////////////////////
//
// class LCPCList;
//
//////////////////////////////////////////////////////////////////////

class LCPCList : public Packet {

public:

	// constructor
	// PCInfo* �迭�� ���� NULL�� �����Ѵ�.
	LCPCList() throw();

	// destructor
	// PCInfo* �迭�� �Ҵ�� ��ü�� �����Ѵ�.
	~LCPCList() throw();
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_LC_PC_LIST; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw();
	
	// get packet's name
	string getPacketName() const throw() { return "LCPCList"; }
	
	// get packet's debug string
	string toString() const throw();
	
public:

	// get/set pc info
	PCInfo* getPCInfo(Slot slot) const throw(NoSuchElementException) 
	{ 
		if(m_pPCInfos[ slot ] == NULL)
			throw NoSuchElementException("no such PC exist in that slot");

		return m_pPCInfos[slot];
	}

	void setPCInfo(Slot slot, PCInfo* pPCInfo) throw(DuplicatedException) 
	{ 
		if(m_pPCInfos[ slot ] != NULL)
			throw DuplicatedException("PCInfo duplicated.");
		m_pPCInfos[slot] = pPCInfo;
	}

	bool isAgree() const { return (m_Agree ? true : false); }
	void setAgree(bool agree ) { m_Agree = agree; }

private : 

	// ĳ���� ����
	PCInfo* m_pPCInfos[ SLOT_MAX ];

	// �ݸ��� ����� ��� ���� ����
	BYTE m_Agree;
};


//////////////////////////////////////////////////////////////////////
//
// class LCPCListFactory;
//
// Factory for LCPCList
//
//////////////////////////////////////////////////////////////////////

class LCPCListFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket() throw() { return new LCPCList(); }

	// get packet name
	string getPacketName() const throw() { return "LCPCList"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_LC_PC_LIST; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize() const throw() 
	{ 
		// �����̾� ������ �����̾� �������� ����� ũ�� ������,
		// �� ��Ŷ�� �ִ� ũ��� �����̾� 3 ���� ����̴�.
		return PCSlayerInfo::getMaxSize()* SLOT_MAX + SLOT_MAX + szBYTE; 
	}
	
};


//////////////////////////////////////////////////////////////////////
//
// class LCPCListHandler;
//
//////////////////////////////////////////////////////////////////////

class LCPCListHandler {

public:

	// execute packet's handler
	static void execute(LCPCList* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};

#endif