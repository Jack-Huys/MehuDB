#pragma once

#define COLUMN_USERNAME_SIZE 128
#define COLUMN_PASSWORD_SIZE 256

#define SIZE_OF_ATTRIBUTE(Struct, Attribute) sizeof(((Struct *)0)->Attribute)

// ÐÐ¼ÇÂ¼
class MehuRow
{
public:

	MehuRow();
	virtual ~MehuRow();

	void SerializeRow(MehuRow &source, void *destination);
	void DeserializeRow(void *source, MehuRow &destination);

private:
	unsigned int m_nId;
	char m_szUsername[COLUMN_USERNAME_SIZE];
	char m_szPassword[COLUMN_PASSWORD_SIZE];


	const unsigned int ID_SIZE = SIZE_OF_ATTRIBUTE(MehuRow, m_nId);
	const unsigned int USERNAME_SIZE = SIZE_OF_ATTRIBUTE(MehuRow, m_szUsername);
	const unsigned int PASSWORD_SIZE = SIZE_OF_ATTRIBUTE(MehuRow, m_szPassword);;
	const unsigned int ROW_SIZE = ID_SIZE + USERNAME_SIZE + PASSWORD_SIZE;

	const unsigned int ID_OFFSET = 0;
	const unsigned int USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
	const unsigned int PASSWORD_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;

};

