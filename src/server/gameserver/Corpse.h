//////////////////////////////////////////////////////////////////////////////
// Filename    : Corpse.h
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __CORPSE_H__
#define __CORPSE_H__

#include "Types.h"
#include "Exception.h"
#include "Item.h"
#include "ItemFactory.h"

//////////////////////////////////////////////////////////////////////////////
// ��ü Ÿ��
//////////////////////////////////////////////////////////////////////////////
enum CorpseType 
{
	SLAYER_CORPSE = 0,
	VAMPIRE_CORPSE,
	NPC_CORPSE,
	MONSTER_CORPSE,
	OUSTERS_CORPSE
};

//////////////////////////////////////////////////////////////////////////////
// class Corpse
//////////////////////////////////////////////////////////////////////////////

class Corpse : public Item 
{
public:
	Corpse() throw();
	virtual ~Corpse() throw();

public:
	virtual ItemClass getItemClass() const throw() { return ITEM_CLASS_CORPSE; }
	virtual string getObjectTableName() const throw() { return ""; }

	virtual ItemType_t getItemType() const throw() = 0;
	virtual void setItemType(ItemType_t monsterType) throw() = 0;

    virtual VolumeWidth_t getVolumeWidth() const throw(Error) { return 0; }
    virtual VolumeHeight_t getVolumeHeight() const throw(Error) { return 0; }
    virtual Weight_t getWeight() const throw(Error) { return 0; }

	virtual string toString() const throw() = 0;

public:
	void addTreasure(Item* pItem) throw();
	Item* getTreasure() throw();
	Item* getTreasure(ObjectID_t objectID ) const throw();
	Item* popTreasure(ObjectID_t objectID ) throw();

	BYTE getTreasureCount() const throw() { return m_TreasureCount; }
	void setTreasureCount(BYTE Count) throw() { m_TreasureCount = Count; }

	ZoneCoord_t getX() const throw() { return m_X; }
	void setX(ZoneCoord_t x) throw() { m_X = x; }

	ZoneCoord_t getY() const throw() { return m_Y; }
	void setY(ZoneCoord_t y) throw() { m_Y = y; }

	// get/set zone
    Zone* getZone() const throw() { return m_pZone; }
    void setZone(Zone* pZone) throw() { m_pZone = pZone; }

	int getLevel() const throw() { return m_Level; }
	void setLevel(int level) throw() { m_Level = level; }

	Exp_t getExp() const throw() { return m_Exp; }
	void setExp(Exp_t exp) throw() { m_Exp = exp; }

protected:
	list<Item*> m_Treasures;     // ������ ����Ʈ
	BYTE        m_TreasureCount; // ������ ����

	// ���� �����븦 ���� �ʻ� ��ǥ �ֱ�
	// �� �ܿ��� ��ǥ�� ����� ���� �ȵ� �� �����Ƿ� ������
	ZoneCoord_t  m_X, m_Y;

	Zone*		m_pZone;

	// ��ü�� �� ������ �� ���±� ;;;
	int 		m_Level;		// ���� -_-;
	Exp_t		m_Exp;			// �̳� ���̰� ���� ����ġ;
	
	// ���Ͱ� Relic���� �ƴ����� �����ϴ� ����
	// ���� Relic�̶��, ������ ��ü�� ������� �ʵ��� �ؾ� �Ѵ�.
};

//////////////////////////////////////////////////////////////////////////////
// class CorpseFactory
//////////////////////////////////////////////////////////////////////////////

class CorpseFactory : public ItemFactory 
{
public:
	Item* createItem(ItemType_t ItemType, const list<OptionType_t>& OptionType) throw() { return NULL; }
	string getItemName() const throw() { return "Corpse"; }
	Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_CORPSE; }
};

#endif