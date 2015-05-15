#include <stddef.h>
#include "Bsp.h"
#include "IUart.h"
#include "DUart.h"
#include "Threads.h"
#include "OS.h"

namespace Bsp {
IUart* g_pUart = NULL;
OS* g_pOS = NULL;
}

int main(void)
{
    DUart uart;
    uart.Init();

    // Initialize global objects
    Bsp::g_pUart = &uart;

    Bsp::InitHardware();

    // Print initialization time
    Bsp::g_pUart->PrintStr("> Chad Bartlett's Assignment 1.\n\n");
    Bsp::g_pUart->PrintStr("> Hardware initialization took: ");
    Bsp::g_pUart->PrintUInt(TIME_TICK_TO_MS(Bsp::GetSysTick()));
    Bsp::g_pUart->PrintStr("-milliseconds\n");

    // Create threads
    Thread::GlobalData_t data;
    Thread::Thread_t th1 = {&Thread::Idle, &data, Thread::UID_THREAD_IDLE, 0, Thread::STATE_INITIAL, "Idle"};
    Thread::Thread_t th2 = {&Thread::Thread1, &data, Thread::UID_THREAD_1, 0, Thread::STATE_INITIAL, "Thread1"};
    Thread::Thread_t th3 = {&Thread::Thread2, &data, Thread::UID_THREAD_2, 0, Thread::STATE_INITIAL, "Thread2"};
    Thread::Thread_t th4 = {&Thread::Thread3, &data, Thread::UID_THREAD_3, 0, Thread::STATE_INITIAL, "Thread3"};

    // Initialize OS
    OS os(uart);
    Bsp::g_pOS = &os;

    // Register Threads
    os.RegisterThread(th1);
    os.RegisterThread(th2);
    os.RegisterThread(th3);
    os.RegisterThread(th4);

    // Start OS; never returns
    os.Start();
}

