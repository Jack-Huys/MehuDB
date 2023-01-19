#pragma once

#include "MehuStatement.h"


#include <iostream>
#include <string>


// 元命令解析结果枚举
enum MetaCommandResult
{
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED_COMMAND
};

// 预处理结果枚举
enum PrepareResult
{
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT
};

// 执行结果枚举
enum ExecuteResult
{
	EXECUTE_SUCCESS,
	EXECUTE_TABLE_FULL
};

class MehuStatement;
class MehuTable;
// 数据库类
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