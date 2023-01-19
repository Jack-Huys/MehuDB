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

// Ԥ������ö��
enum PrepareResult
{
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT
};

// ִ�н��ö��
enum ExecuteResult
{
	EXECUTE_SUCCESS,
	EXECUTE_TABLE_FULL
};

class MehuStatement;
class MehuTable;
// ���ݿ���
class MehuDB
{
public:
	void Start();


private:

	void PrintPrompt();
	bool ParseMetaCommand(std::string& command);
	MetaCommandResult DoMetaCommand(std::string& command);

	PrepareResult PrepareStatement(std::string& input_line, MehuStatement& statement);
	bool ParseStatement(std::string& input_line, MehuStatement& statement);
	void ExecuteStatement(MehuStatement& statement);

	ExecuteResult ExecuteInsert(MehuStatement& statement, MehuTable& table);
	ExecuteResult ExecuteSelect(MehuStatement& statement, MehuTable& table);

};