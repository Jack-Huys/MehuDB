#include "MehuRow.h"

#include <string>

MehuRow::MehuRow()
{

}

MehuRow::~MehuRow()
{

}

void MehuRow::SerializeRow(MehuRow &source, void *destination)
{
	memcpy((char *)destination + ID_OFFSET, &(source.m_nId), ID_SIZE);
	memcpy((char *)destination + USERNAME_OFFSET, &(source.m_szUsername), USERNAME_SIZE);
	memcpy((char *)destination + PASSWORD_OFFSET, &(source.m_szPassword), PASSWORD_SIZE);
}
void MehuRow::DeserializeRow(void *source, MehuRow &destination)
{
	memcpy(&(destination.m_nId), (char *)source + ID_OFFSET, ID_SIZE);
	memcpy(&(destination.m_szUsername), (char *)source + USERNAME_OFFSET, USERNAME_SIZE);
	memcpy(&(destination.m_szPassword), (char *)source + PASSWORD_OFFSET, PASSWORD_SIZE);
}

