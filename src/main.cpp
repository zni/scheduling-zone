/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Driver for the scheduling simulator.
 *                  TODO Add command line processing.
 *
 *        Version:  1.0
 *        Created:  09/05/2012 12:20:42 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */

#include <iostream>
#include "processtable.h"
#include "priorityquantum.h"
#include "roundrobin.h"

int main(int argc, char **argv)
{
    ProcessTable ptable(400, 1000);
    ProcessTable::ProcStats procStats;
    // RoundRobin sched(100);
    PriorityQuantum sched(100);

    ptable.dump();
    std::cout << std::endl;

    std::cout << "running scheduler..." << std::endl;
    sched.run(ptable, 10000);
    std::cout << "done." << std::endl;

    std::cout << "statistics" << std::endl;
    procStats = ptable.stats();
    std::cout << "\tprocesses scheduled: " << procStats.scheduled << std::endl;
    std::cout << "\tprocesses complete: " << procStats.complete << std::endl;
    std::cout << "\tprocesses incomplete: " << procStats.incomplete << std::endl;
    std::cout << "\tavg. process length: " << procStats.avgTime 
                                           << "ms" << std::endl;

    return 0;
}
