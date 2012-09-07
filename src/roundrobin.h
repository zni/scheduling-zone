/*
 * =====================================================================================
 *
 *       Filename:  roundrobin.h
 *
 *    Description:  Round-Robin header file
 *
 *        Version:  1.0
 *        Created:  09/05/2012 08:10:15 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */

#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include <queue>
#include "scheduler.h"

class ProcessTable;
class Process;
class RoundRobin : public Scheduler
{
    public:
        RoundRobin(const int &quantum = 100);
        ~RoundRobin();

        void run(const ProcessTable &ptable, const int &runningTime = 5000);

    private:
        std::queue<Process*> m_queue;
        int m_quantum;
};

#endif

