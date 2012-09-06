/*
 * =====================================================================================
 *
 *       Filename:  process.cpp
 *
 *    Description:  Process implementation
 *
 *        Version:  1.0
 *        Created:  09/05/2012 01:43:19 AM
 *       Revision:  none
 *       Compiler:  clang++
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */

#include "process.h"

Process::Process(const int &pid, const int &ptime)
    : m_pid(pid),
      m_ptime(ptime)
{ }


Process::~Process() { }


int Process::pid() const
{
    return m_pid;
}


char Process::priority() const
{
    return m_priority;
}


void Process::setPriority(const char &priority)
{
    m_priority = priority;
}


int Process::ptime() const
{
    return m_ptime;
}


void Process::run(const int &time)
{
    if ((this->m_ptime - time) < 0)
        this->m_ptime = 0;
    else 
        this->m_ptime -= time;
}
