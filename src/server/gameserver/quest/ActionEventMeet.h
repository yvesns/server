//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionEventMeet.h
// Written By  : excel96
// Description : 
// Creature�� PC���� ������ ������. �� ���� NPC ��ȭâ�� ��µȴ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_EVENT_MEET_H__
#define __ACTION_EVENT_MEET_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionEventMeet
//////////////////////////////////////////////////////////////////////////////

class ActionEventMeet : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_EVENT_MEET; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

public:

private:
	ScriptID_t m_ScriptID;   // ���� ��� ���̵�
	ScriptID_t m_CounterScriptID;
	bool m_bGiveInfo;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionEventMeetFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionEventMeetFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_EVENT_MEET; }
	virtual string getActionName() const throw() { return "EventMeet"; }
	virtual Action* createAction() const throw() { return new ActionEventMeet(); }
};
#endif