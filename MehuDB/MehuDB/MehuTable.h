#pragma once
#include <iostream>
#include "MehuRow.h"

#define TABLE_MAX_PAGES 100
const unsigned int PAGE_SIZE = 4096;
const unsigned int ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
const unsigned int TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

class MehuTable
{
public:

	MehuTable();
	virtual ~MehuTable();

	void* RowSlot(MehuTable& table, uint32_t row_num);

public:
	unsigned int m_nRowCount;                   // ÐÐÊý
	void *m_pPages[TABLE_MAX_PAGES];            // Ò³Êý
};

