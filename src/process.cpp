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
 *       Compiler:  g++
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */

#include "process.h"

Process::Process(const int &pid, const int &ptime, const int &priority)
    : m_pid(pid),
      m_ptime(ptime),
      m_priority(priority),
      m_scheduled(false)
{ }


Process::~Process() { }


int Process::pid() const
{
    return m_pid;
}


int Process::priority() const
{
    return m_priority;
}


void Process::setPriority(const int &priority)
{
    m_priority = priority;
}


int Process::ptime() const
{
    return m_ptime;
}


void Process::run(const int &time)
{
    if (!m_scheduled)
        m_scheduled = true;

    if ((this->m_ptime - time) < 0)
        this->m_ptime = 0;
    else 
        this->m_ptime -= time;
}


bool Process::scheduled() const
{
    return m_scheduled;
}


bool operator> (Process &p, Process &q)
{
    return p.m_priority > q.m_priority;
}


bool operator<= (Process &p, Process &q)
{
    return p.m_priority <= q.m_priority;
}


bool operator< (Process &p, Process &q)
{
    return p.m_priority < q.m_priority;
}


bool operator>= (Process &p, Process &q)
{
    return p.m_priority >= q.m_priority;
}

