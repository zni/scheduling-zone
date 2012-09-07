/*
 * =====================================================================================
 *
 *       Filename:  processtable.h
 *
 *    Description:  Process table class header.
 *
 *        Version:  1.0
 *        Created:  09/05/2012 12:31:39 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */
#ifndef PROCESS_TABLE_H
#define PROCESS_TABLE_H

#include <vector>

class Process;
class ProcessTable
{
    public:
        ProcessTable(const int &numberOfProcs);
        ~ProcessTable();

        struct ProcStats {
            int complete;
            int incomplete;
            double avgTime;
        };

        Process* findPid(const int &pid) const;
        void dump() const;
        std::vector<Process*> table() const;
        int size() const;
        ProcessTable::ProcStats stats();

    private:
        std::vector<Process*> m_table;
        ProcessTable::ProcStats m_stats;

};
#endif

