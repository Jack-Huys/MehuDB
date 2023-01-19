#pragma once
#include "MehuRow.h"


// SQL”Ôæ‰¿‡–Õ
enum StatementType
{
	STATEMENT_UNKNOWN,
	STATEMENT_INSERT,
	STATEMENT_SELECT
};

class MehuStatement
{

public:
	MehuStatement();
	virtual ~MehuStatement();

	StatementType GetStatementType() const;
	void SetStatementType(StatementType statementType);

public:
	MehuRow m_stuRow;

private:
	StatementType m_emStatementType;
};


