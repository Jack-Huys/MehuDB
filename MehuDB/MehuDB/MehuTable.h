#pragma once
#include <iostream>

#define TABLE_MAX_PAGES 100
const unsigned int PAGE_SIZE = 4096;
//const unsigned int ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
//const unsigned int TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

class MehuTable
{
public:

	MehuTable()
	{
		m_nRowCount = 0;
		for (unsigned int i = 0; i < TABLE_MAX_PAGES; i++)
		{
			m_pPages[i] = NULL;
		}
	}
	~MehuTable()
	{
		for (int i = 0; m_pPages[i]; i++)
		{
			free(m_pPages[i]);
		}
	}

private:
	unsigned int m_nRowCount;
	void *m_pPages[TABLE_MAX_PAGES];
};

