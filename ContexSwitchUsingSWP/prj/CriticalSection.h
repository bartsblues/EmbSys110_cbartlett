/**
 *******************************************************************************
 *  @filename   CriticalSection.h
 *  @brief      See implementation file for class description.
 *  @author     Chad Bartlett   <cbartlet@uw.edu>
 *******************************************************************************
 */
#ifndef CRITICAL_SECTION_H
#define CRITICAL_SECTION_H

#include "bsp.h"

class CriticalSection
{
  public:
    CriticalSection();
    ~CriticalSection();

    typedef enum
    {
        SUCCESS,
        BUSY,
        RESOURCES
    } Status_t;

    Status_t Enter(int threadID);
    Status_t Leave(int threadID);
    Status_t Query(int threadID);

  private:
    void ResetDataMembers();

    volatile CSStatus_t m_lockedState;
    volatile int m_nLocks;
    volatile int m_currThreadID;
};

#endif // #ifndef CRITICAL_SECTION_H
