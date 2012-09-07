/*
 * =====================================================================================
 *
 *       Filename:  scheduler.h
 *
 *    Description:  Scheduler header file
 *
 *        Version:  1.0
 *        Created:  09/05/2012 02:40:22 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

class ProcessTable;
class Scheduler
{
    public:
        virtual void run(const ProcessTable &ptable, const int &runningTime) = 0;
};

#endif

