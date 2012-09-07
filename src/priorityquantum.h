/*
 * =====================================================================================
 *
 *       Filename:  priorityquantum.h
 *
 *    Description:  Priority (with quantum) scheduling header file
 *
 *        Version:  1.0
 *        Created:  09/07/2012 01:59:54 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */

#ifndef PRIORITYQUANTUM_H
#define PRIORITYQUANTUM_H

#include <queue>
#include "scheduler.h"

class ProcessTable;
class Process;
class PriorityQuantum : public Scheduler
{
    public:
        PriorityQuantum(const int &quantum = 100);
        ~PriorityQuantum();

        void run(const ProcessTable &ptable, const int &runningTime = 5000);

    private:
        std::priority_queue<Process*> m_pqueue;
        int m_quantum;
};
#endif
