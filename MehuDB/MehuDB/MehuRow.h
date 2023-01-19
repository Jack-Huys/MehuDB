#pragma once

#define COLUMN_USERNAME_SIZE 128
#define COLUMN_PASSWORD_SIZE 256

#define SIZE_OF_ATTRIBUTE(Struct, Attribute) sizeof(((Struct *)0)->Attribute)

// 行记录
class MehuRow
{
public:

	MehuRow();
	virtual ~MehuRow();

	void SerializeRow(MehuRow &source, void *destination);
	void DeserializeRow(void *source, MehuRow &destination);

public:
	unsigned int m_nId;
	char m_szUsername[COLUMN_USERNAME_SIZE];
	char m_szPassword[COLUMN_PASSWORD_SIZE];
};

// 行字段大小
const unsigned int ID_SIZE = SIZE_OF_ATTRIBUTE(MehuRow, m_nId);
const unsigned int USERNAME_SIZE = SIZE_OF_ATTRIBUTE(MehuRow, m_szUsername);
const unsigned int PASSWORD_SIZE = SIZE_OF_ATTRIBUTE(MehuRow, m_szPassword);

// 行大小
const unsigned int ROW_SIZE = ID_SIZE + USERNAME_SIZE + PASSWORD_SIZE;

// 行字段偏移
const unsigned int ID_OFFSET = 0;
const unsigned int USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
const unsigned int PASSWORD_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;