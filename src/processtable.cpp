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
 *       Compiler:  g++
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

ProcessTable::ProcessTable(const int &numberOfProcs,
                           const int &maxExecutionTime)
    : m_table(numberOfProcs)
{
    m_table.reserve(numberOfProcs);
    m_stats.scheduled = 0;
    m_stats.complete = 0;
    m_stats.incomplete = 0;
    m_stats.avgTime = 0.0;
    
    /* Initialize process table */
    int ptime;
    int priority;
    srand(time(NULL));
    for (int i = 0; i < numberOfProcs; ++i) {
        ptime = rand() % maxExecutionTime;
        priority = rand() % 20;
        m_table[i] = new Process(i + 1, ptime, priority);
        m_stats.avgTime += ptime;
    }

    m_stats.avgTime = m_stats.avgTime / numberOfProcs;
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
        return m_table[pid - 1];

    return NULL;
}


void ProcessTable::dump() const
{
    std::cout << "process table" << std::endl;
    for (int i = 0; i < m_table.size(); ++i) {
        std::cout << "process" << std::endl;
        std::cout << "\tpid: " << m_table[i]->pid() << std::endl;
        std::cout << "\tpriority: " << m_table[i]->priority() << std::endl;
        std::cout << "\tptime: " << m_table[i]->ptime() << std::endl;
        std::cout << std::endl;
    }
}


int ProcessTable::size() const
{
    return m_table.size();
}


ProcessTable::ProcStats ProcessTable::stats()
{
    for (int i = 0; i < m_table.size(); ++i) {
        if (m_table[i]->ptime() == 0)
            ++m_stats.complete;
        else
            ++m_stats.incomplete;

        if (m_table[i]->scheduled())
            ++m_stats.scheduled;
    }

    return m_stats;
}
