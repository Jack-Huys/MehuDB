#include "MehuStatement.h"


MehuStatement::MehuStatement()
	:m_emStatementType(STATEMENT_UNKNOWN)
{
}

MehuStatement::~MehuStatement()
{
}

void MehuStatement::SetStatementType(StatementType statementType)
{
	m_emStatementType = statementType;
}

StatementType MehuStatement::GetStatementType() const
{
	return m_emStatementType;
}