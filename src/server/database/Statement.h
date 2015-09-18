//////////////////////////////////////////////////////////////////////
//
// File Name 	: Statement.h
// Written by	: Gday29@ewestsoft.com
// Description	: SQL ���� �����..
//
//////////////////////////////////////////////////////////////////////

#ifndef __STATEMENT_H__
#define __STATEMENT_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Connection.h"

// forward declaration
class Result;

//////////////////////////////////////////////////////////////////////
//
// class Statement;
//
// SQL���� ����� ��� �����Ѵ�.
//
//////////////////////////////////////////////////////////////////////

class Statement {

public:
	
	// constructor
	Statement() throw(); 

	// constructor
    Statement(char * fmt, ...) throw(Error);

	// destructor
	~Statement() throw();

public:
    
	// ������ ������ SQL ���� ������ �����Ѵ�.
    Result * executeQuery() throw(SQLQueryException, Error);
	
	// SQL ���� �޾Ƽ� �����Ѵ�.
	Result * executeQuery(const char *,...) throw(SQLQueryException, Error);
	Result * executeQuery(const string& sqlStatement) throw(SQLQueryException, Error);
	
	// get SQL statement
	string getStatement() const throw() { return m_Statement; }

	// SQL ���� �����Ѵ�.
	void setStatement(char * fmt, ...) throw(Error);

	// get connection object
	Connection * getConnection() const throw() { return m_pConnection; }

	// set connection object
	void setConnection(Connection * pConnection) throw() { m_pConnection = pConnection; }

	// get warning/error string
	string getError() const throw() 
	{ 
		return(m_pConnection == NULL) ?("Not Associated with Connection Object") :(m_pConnection->getError()); 
	}

	// get affected rows
	uint getAffectedRowCount() const throw() { return m_nAffectedRows; }

	// get insert id
	uint getInsertID() const throw();

	
private:
	
	// Connection
	Connection * m_pConnection;

	// SQL Statement�
	string m_Statement;

	// Query Result 
	Result * m_pResult;

	// insert, update, delete ���� �� ������ ���� row �� ����
	uint m_nAffectedRows;

};

#endif // __STATEMENT_H__