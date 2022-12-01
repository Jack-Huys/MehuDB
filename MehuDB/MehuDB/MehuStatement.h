#pragma once


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


private:
	StatementType m_emStatementType;
};


