//--------------------------------------------------------------------
//
//  Laboratory 7, Programming Exercise 1                   storesim.cs
//
//  Program implementation shell.
//
//--------------------------------------------------------------------

// Simulates the flow of customers through a line in a store.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// Use which ever implementation is currently configured.
#if LAB7_TEST1
#   include "QueueLinked.h"
#else
#   include "QueueArray.h"
#endif

using namespace std;

int main ()
{
#if LAB7_TEST1
    QueueLinked<int> custQ;      // Line (queue) of customers containing the
#else
    QueueArray<int> custQ;       // Line (queue) of customers containing the
#endif                  //   time that each customer arrived and
    //   joined the line
    int simLength,               // Length of simulation (minutes)
    minute,                  // Current minute
    timeArrived,             // Time dequeued customer arrived
    waitTime,                // How long dequeued customer waited
    totalServed = 0,         // Total customers served
    totalWait   = 0,         // Total waiting time
    maxWait     = 0,         // Longest wait
    numArrivals = 0;         // Number of new arrivals
    
    // Seed the random number generator. Equally instructive to run the
    // simulation with the generator seeded and not seeded.
    srand( time(NULL) );
    
    cout << endl << "Enter the length of time to run the simulator : ";
    cin >> simLength;
    
    // Put your code here to run this simulation. Use "rand()" to get
    // a pseudorandom number that you can use to calculate probabilities.
    minute = 0;
    int a;
    while(minute <= simLength)
    {
        minute++;
        int custTemp = 0;
        
        if(!custQ.isEmpty())
        {
            timeArrived = custQ.dequeue();
            waitTime = minute - timeArrived;
            totalWait += waitTime;
            totalServed++;
            
            if(waitTime > maxWait)
            {
                maxWait = waitTime;
            }
            timeArrived = custTemp;
        }
        
        a = rand() % 4;
        
        if(a == 1)
        {
            numArrivals++;
        }
        
        else if (a == 2)
        {
            numArrivals += 2;
        }
        
        for(int i = 0; i < numArrivals; i++)
        {
            custQ.enqueue(minute);
        }
        
        numArrivals = 0;
    }
    
    
    // Print out simulation results
    cout << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)
    << double(totalWait)/totalServed << endl;
    cout << "Longest wait     : " << maxWait << endl;
    
    return 0;
}
