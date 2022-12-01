#include "MehuDB.h"


void MehuDB::print_prompt()
{
	std::cout << "MehuDB > ";
}

bool MehuDB::parse_meta_command(std::string &command)
{
	if (command[0] == '.')
	{
		switch (do_meta_command(command))
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
MetaCommandResult MehuDB::do_meta_command(std::string &command)
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

PrepareResult MehuDB::prepare_statement(std::string &input_line, MehuStatement &statement)
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

bool MehuDB::parse_statement(std::string &input_line, MehuStatement &statement)
{
	switch (prepare_statement(input_line, statement))
	{
	case PREPARE_SUCCESS:
		return false;
	case PREPARE_UNRECOGNIZED_STATEMENT:
		std::cout << "Unrecognized keyword at start of '" << input_line << "'." << std::endl;
		return true;
	}
	return false;
}

void MehuDB::execute_statement(MehuStatement &statement)
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



void MehuDB::start()
{
	while (true)
	{
		print_prompt();

		std::string input_line;
		std::getline(std::cin, input_line);

		if (parse_meta_command(input_line))
		{
			continue;
		}

		MehuStatement statement;

		// SQL解析
		if (parse_statement(input_line, statement))
		{
			continue;
		}

		// 执行SQL
		execute_statement(statement);
	}
}