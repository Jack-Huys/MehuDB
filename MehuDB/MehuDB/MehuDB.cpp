#include "MehuDB.h"

#include "MehuTable.h"

void MehuDB::Start()
{
	while (true)
	{
		PrintPrompt();

		std::string input_line;
		std::getline(std::cin, input_line);

		if (ParseMetaCommand(input_line))
		{
			continue;
		}

		MehuStatement statement;

		// SQL解析
		if (ParseStatement(input_line, statement))
		{
			continue;
		}

		// 执行SQL
		ExecuteStatement(statement);
	}
}

void MehuDB::PrintPrompt()
{
	std::cout << "MehuDB > ";
}

bool MehuDB::ParseMetaCommand(std::string &command)
{
	if (command[0] == '.')
	{
		switch (DoMetaCommand(command))
		{
		case META_COMMAND_SUCCESS:
			return true;
		case META_COMMAND_UNRECOGNIZED_COMMAND:
			std::cout << "Unrecognized command: " << command << std::endl;
			return true;
		}
	}
	return false;
}
MetaCommandResult MehuDB::DoMetaCommand(std::string &command)
{
	if (command == ".exit")
	{
		std::cout << "再见! 欢迎下次使用MehuDB!" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else
	{
		return META_COMMAND_UNRECOGNIZED_COMMAND;
	}
}

PrepareResult MehuDB::PrepareStatement(std::string &input_line, MehuStatement &statement)
{
	if (!input_line.compare(0, 6, "insert"))
	{
		statement.SetStatementType(STATEMENT_INSERT);
		return PREPARE_SUCCESS;
	}
	else if (!input_line.compare(0, 6, "select"))
	{
		statement.SetStatementType(STATEMENT_SELECT);
		return PREPARE_SUCCESS;
	}
	else
	{
		return PREPARE_UNRECOGNIZED_STATEMENT;
	}
}

bool MehuDB::ParseStatement(std::string &input_line, MehuStatement &statement)
{
	switch (PrepareStatement(input_line, statement))
	{
	case PREPARE_SUCCESS:
		return false;
	case PREPARE_UNRECOGNIZED_STATEMENT:
		std::cout << "Unrecognized keyword at start of '" << input_line << "'." << std::endl;
		return true;
	}
	return false;
}

void MehuDB::ExecuteStatement(MehuStatement &statement)
{
	switch (statement.GetStatementType())
	{
	case STATEMENT_INSERT:
		std::cout << "Executing insert statement" << std::endl;
		break;
	case STATEMENT_SELECT:
		std::cout << "Executing select statement" << std::endl;
		break;
	}
}

ExecuteResult MehuDB::ExecuteInsert(MehuStatement& statement, MehuTable& table)
{
	if (table.m_nRowCount>= TABLE_MAX_ROWS)
	{
		std::cout << "Error: Table full." << std::endl;
		return EXECUTE_TABLE_FULL;
	}

	void* page = table.RowSlot(table, table.m_nRowCount);
	MehuRow _stuMehuRow;
	_stuMehuRow.SerializeRow(statement.m_stuRow, page);
	
	table.m_nRowCount++;

	return EXECUTE_SUCCESS;
}

ExecuteResult MehuDB::ExecuteSelect(MehuStatement& statement, MehuTable& table)
{
	for (uint32_t i = 0; i < table.m_nRowCount; i++)
	{
		MehuRow _row;
		void* page = table.RowSlot(table, i);
		//deserialize_row(page, _row);
		std::cout << "(" << _row.m_nId << ", " << _row.m_szUsername << ", " << _row.m_szPassword << ")" << std::endl;
	}

	return EXECUTE_SUCCESS;
}

