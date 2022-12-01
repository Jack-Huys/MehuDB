#pragma once

#include "MehuStatement.h"

#include <iostream>
#include <string>


// Ԫ����������ö��
enum MetaCommandResult
{
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED_COMMAND
};

// ������ö��
enum PrepareResult
{
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT
};

// ���ݿ���
class MehuDB
{

public:
	void start();
	void print_prompt();

	bool parse_meta_command(std::string &command);
	MetaCommandResult do_meta_command(std::string &command);

	PrepareResult prepare_statement(std::string &input_line, MehuStatement &statement);
	bool parse_statement(std::string &input_line, MehuStatement &statement);
	void execute_statement(MehuStatement &statement);


private:


};