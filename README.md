# Philosophers

## Table of Contents

- [About the Project](#about-the-project)
- [Resources](#resources)

## About the Project

The dining philosophers problem is a classic computer science problem proposed by Edsger Dijkstra in 1965 to illustrate the issue of process synchronization in an operating system. The problem involves a hypothetical scenario where five philosophers sit around a round table, each with a plate of pasta and a fork between each pair of adjacent philosophers. The challenge lies in allowing each philosopher to alternate between two states—thinking and eating—without causing deadlocks while trying to acquire the adjacent forks needed to eat. A thinking philosopher is analogous to a process performing actions that do not affect other processes. A philosopher who is eating represents a process managing a shared resource, thus impacting other processes.

There are three main issues that arise when implementing concurrency in computers:

- Deadlock: When writing a program that needs access to a shared resource, you might develop a program that checks if the resource is available, pauses if it’s not and checks again after waiting a while. Seems sensible. But what if other programs were also designed like this? Let’s use an example of file handling. A file is shared resource, so we can only ever allow a file to be written to by one process at a time. Let’s say process P1 is currently writing to the accounts file. P1 therefore has exclusive access to it at that moment. P1 then decides it also needs to write to the personnel file, but it finds that a different process, P2, is currently using the personnel file. Each process is waiting for the other to make a move, but the condition for either process making a move is that the other process makes a move! Like two painfully shy people in love, each is waiting interminably for the other and the whole situation proceeds no further. Not only have both processes deadlocked themselves, they’ve also locked up the resources they’re holding (files X and Y) so that no other process can use them.

- Starvation: When a process never gets a chance to access the shared resource because of the scheduling desing. Starvation is dealt with by improving the scheduling approach. Operating systems can use a number of techniques to guarantee that every process gets some minimum level of attention. One such technique is called ageing. Using this approach, the operating system looks out for processes that have gone unrun for a long time and assigns such processes a higher priority. This lets them “jump the queue” and get dealt with ahead of the competing processes that are starving it.

- Race Conditions: A race condition in concurrency occurs when two or more threads or processes access shared resources (like variables or files) at the same time, and the final outcome depends on the timing of their execution. This can lead to unpredictable or incorrect behavior. A critical section is a part of the code where shared resources are accessed or modified. To prevent race conditions, only one thread should enter a critical section at a time.


Synchronization Tools

- Locks/Mutexes: Ensure only one thread can access a resource at a time.
- Semaphores: Allow a set number of threads to access a resource.
- Barriers: Synchronize threads at a certain point in execution.
- Condition Variables: Allow threads to wait for certain conditions to be met.

## Resources

- [Code(quoi)](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/)
- [Medium-article](https://medium.com/great-moments-in-computing-history/the-dining-philosophers-2e3da2847bac)
