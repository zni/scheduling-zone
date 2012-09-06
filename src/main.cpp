/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Driver for the scheduling simulator.
 *
 *        Version:  1.0
 *        Created:  09/05/2012 12:20:42 AM
 *       Revision:  none
 *       Compiler:  clang++
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */

#include <iostream>
#include "processtable.h"
#include "roundrobin.h"

int main(int argc, char **argv)
{
    ProcessTable ptable(100);
    ProcessTable::ProcStats procStats;
    RoundRobin sched(50);

    std::cout << "running scheduler..." << std::endl;
    sched.run(ptable);
    std::cout << "done." << std::endl;

    std::cout << "statistics" << std::endl;
    procStats = ptable.stats();
    std::cout << "\tcomplete: " << procStats.complete << std::endl;
    std::cout << "\tincomplete: " << procStats.incomplete << std::endl;
    std::cout << "\tavg. process time: " << procStats.avgTime 
                                         << "ms" << std::endl;

    return 0;
}
