//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCAttackArmsOK1.h 
// Written By  : elca@ewestsoft.com
// Description : ����� ���������� ������ ��Ŷ�� ���� Ŭ���� ����
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_ATTACK_ARMS_OK_1_H__
#define __GC_ATTACK_ARMS_OK_1_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "ModifyInfo.h"
#include "PacketFactory.h"
//#include "ModifyItemInfo.h"

//////////////////////////////////////////////////////////////////////
//
// class GCAttackArmsOK1;
//
// ���Ӽ������� Ŭ���̾�Ʈ�� �ڽ��� ����� ������ �˷��ֱ� ���� Ŭ����
//
//////////////////////////////////////////////////////////////////////

class GCAttackArmsOK1 : public ModifyInfo {

public :
	
	// constructor
	GCAttackArmsOK1() throw();
	
	// destructor
	~GCAttackArmsOK1() throw();

	
public :
	
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GC_ATTACK_ARMS_OK_1; }
	
	// get packet's body size
	// ����ȭ��, �̸� ���� ������ ����Ѵ�.
	PacketSize_t getPacketSize() const throw() { return szSkillType + szObjectID + szBullet + szbool + ModifyInfo::getPacketSize() ;}

	// get packet's name
	string getPacketName() const throw() { return "GCAttackArmsOK1"; }
	
	// get packet's debug string
	string toString() const throw();

	SkillType_t getSkillType() const { return m_SkillType; }
	void setSkillType(SkillType_t skillType ) { m_SkillType = skillType; }
	// get / set Success
	bool getSkillSuccess() const throw() { return m_bSuccess; }
	void setSkillSuccess(bool Success) throw() { m_bSuccess = Success; }
	
	// get / set ObjectID
	ObjectID_t getObjectID() const throw() { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID) throw() { m_ObjectID = ObjectID; }

	// get / set Bullet Num
	Bullet_t getBullet() const throw() { return m_BulletNum; }
	void setBulletNum(Bullet_t BulletNum) { m_BulletNum = BulletNum; }

private :

	SkillType_t m_SkillType;
	// ObjectID
	ObjectID_t m_ObjectID;

	// Bullet Num
	Bullet_t m_BulletNum;

	// success(damage �� ������?)
	bool m_bSuccess;

};


//////////////////////////////////////////////////////////////////////
//
// class GCAttackArmsOK1Factory;
//
// Factory for GCAttackArmsOK1
//
//////////////////////////////////////////////////////////////////////

class GCAttackArmsOK1Factory : public PacketFactory {

public :
	
	// constructor
	GCAttackArmsOK1Factory() throw() {}
	
	// destructor
	virtual ~GCAttackArmsOK1Factory() throw() {}

	
public :
	
	// create packet
	Packet* createPacket() throw() { return new GCAttackArmsOK1(); }

	// get packet name
	string getPacketName() const throw() { return "GCAttackArmsOK1"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_ATTACK_ARMS_OK_1; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const throw() { return szSkillType + szObjectID + szBullet + szbool + ModifyInfo::getPacketMaxSize(); }

};


//////////////////////////////////////////////////////////////////////
//
// class GCAttackArmsOK1Handler;
//
//////////////////////////////////////////////////////////////////////

class GCAttackArmsOK1Handler {

public :

	// execute packet's handler
	static void execute(GCAttackArmsOK1* pGCAttackArmsOK1, Player* pPlayer) throw(Error);

};

#endif