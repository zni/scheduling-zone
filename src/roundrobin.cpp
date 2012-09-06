/*
 * =====================================================================================
 *
 *       Filename:  roundrobin.cpp
 *
 *    Description:  Round-Robin scheduling algorithm.
 *
 *        Version:  1.0
 *        Created:  09/05/2012 08:02:57 PM
 *       Revision:  none
 *       Compiler:  clang++
 *
 *         Author:  mgodshall 
 *
 * =====================================================================================
 */

#include <iostream>
#include <ctime>
#include "process.h"
#include "processtable.h"
#include "roundrobin.h"


RoundRobin::RoundRobin()
    : m_queue(),
      m_quantum(100)
{ }


RoundRobin::RoundRobin(const int &quantum)
    : m_queue(),
      m_quantum(quantum)
{ }


RoundRobin::~RoundRobin()
{ }


void RoundRobin::run(const ProcessTable &ptable)
{
    struct timespec burst;
    int cpuBurst = 10; // 10 milliseconds
    int cycles = m_quantum / cpuBurst;

    burst.tv_sec = 0;
    burst.tv_nsec = cpuBurst * 1000000L;

    /*
        Simulate CPU bursts of 10ms. In doing this we can simulate a block and 
        process switch if we've finished processing something before our quantum
        of 100ms expires.
    */
    Process *proc;
    for (int j = 1; j < ptable.size(); ++j) {
        m_queue.push(ptable.findPid(j));
        proc = m_queue.front();
        for (int i = 0; i < cycles; ++i) {
            if (proc->ptime() == 0)
                break;
            nanosleep(&burst, (struct timespec*) NULL);
            proc->run(cpuBurst);
        }

        if (proc->ptime() == 0) {
            m_queue.pop();
        } else {
            m_queue.push(m_queue.front());
            m_queue.pop();
        }
    }
}
