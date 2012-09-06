/*
 * =====================================================================================
 *
 *       Filename:  processtable.cpp
 *
 *    Description:  Process table
 *
 *        Version:  1.0
 *        Created:  09/05/2012 12:55:11 AM
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "processtable.h"
#include "process.h"

ProcessTable::ProcessTable(const int &numberOfProcs)
    : m_table(numberOfProcs)
{
    int ptime;
    srand(time(NULL));

    m_table.reserve(numberOfProcs);
    
    /* Initialize process table */
    for (int i = 0; i < numberOfProcs; ++i) {
        ptime = rand();
        m_table[i] = new Process(i + 1, ptime % 500);
    }

}


ProcessTable::~ProcessTable()
{
    for (int i = 0; i < m_table.size(); ++i) {
        delete m_table[i];
        m_table[i] = NULL;
    }
}


Process* ProcessTable::findPid(const int &pid) const
{
    if (pid > 0 && pid <= m_table.size())
        return m_table[pid];

    return NULL;
}


void ProcessTable::dump() const
{
    std::cout << "process table" << std::endl;
    for (int i = 0; i < m_table.size(); ++i) {
        std::cout << "process" << std::endl;
        std::cout << "\tpid: " << m_table[i]->pid() << std::endl;
        std::cout << "\tptime: " << m_table[i]->ptime() << std::endl;
        std::cout << std::endl;
    }
}


int ProcessTable::size() const
{
    return m_table.size();
}


void ProcessTable::stats() const
{

}
