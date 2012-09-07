/*
 * =====================================================================================
 *
 *       Filename:  priorityquantum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/07/2012 02:10:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <ctime>
#include <chrono>
#include "process.h"
#include "processtable.h"
#include "priorityquantum.h"


PriorityQuantum::PriorityQuantum(const int &quantum)
    : m_pqueue(),
      m_quantum(quantum)
{ }


PriorityQuantum::~PriorityQuantum()
{ }


void PriorityQuantum::run(const ProcessTable &ptable, const int &runningTime)
{
    /*
     * Assume CPU bursts of 10ms. In doing this we can simulate blocking and 
     * process switch if we've finished processing something before our quantum
     * expires.
     */
    struct timespec burst;
    int cpuBurst = 10;
    int cycles = m_quantum / cpuBurst;
    burst.tv_sec = 0;
    burst.tv_nsec = cpuBurst * 1000000L;

    Process *proc;
    int pid = 1;
    int numProcs = ptable.size() + 1;

    std::chrono::duration<int, std::milli> limit(runningTime);
    auto start = std::chrono::high_resolution_clock::now();
    auto now = start;
    do {
        // Start a process.
        if (pid < numProcs) {
            m_pqueue.push(ptable.findPid(pid));
            ++pid;
        }

        if (!m_pqueue.empty()) {
            proc = m_pqueue.top();
            m_pqueue.pop();
        } else {
            break;
        }

        std::cout << "now processing pid " << proc->pid() << "..." << std::endl;

        for (int i = 0; i < cycles; ++i) {
            if (proc->ptime() == 0)
                break;
            nanosleep(&burst, (struct timespec*) NULL);
            proc->run(cpuBurst);
        }

        if (proc->ptime() != 0)
            m_pqueue.push(proc);

        now = std::chrono::high_resolution_clock::now(); 
    } while ((now - start) < limit);
}

