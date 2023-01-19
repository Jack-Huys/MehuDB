#include "MehuTable.h"

MehuTable::MehuTable()
{
	m_nRowCount = 0;
	for (unsigned int i = 0; i < TABLE_MAX_PAGES; i++)
	{
		m_pPages[i] = NULL;
	}
}

MehuTable::~MehuTable()
{
	for (int i = 0; m_pPages[i]; i++)
	{
		free(m_pPages[i]);
	}
}

void* MehuTable::RowSlot(MehuTable& table, uint32_t row_num)
{
	uint32_t _nPageNum = row_num / ROWS_PER_PAGE;
	void* _pPage = table.m_pPages[_nPageNum];
	if (_pPage == NULL)
	{
		// Allocate memory only when we try to access page
		_pPage = table.m_pPages[_nPageNum] = malloc(PAGE_SIZE);
	}
	uint32_t _nRowOffset = row_num % ROWS_PER_PAGE;
	uint32_t _nByteOffset = _nRowOffset * ROW_SIZE;
	return (char*)_pPage + _nByteOffset;
}
