# Data-Structure-Algorithm
Data structures and algorithms

# zombie,orphan process

A process that has terminated, but whose parent has not yet called wait(), is known as a zombie process. All processes transition to this state when they terminate, but generally they exist as zombies only briefly. Once the parent calls wait(), the process identifier of the zombie process and its entry in the process table are released.
Now consider what would happen if a parent did not invoke wait() and instead terminated, thereby leaving its child processes as orphans. Linux and UNIX address this scenario by assigning the init process as the new parent to orphan processes.


# Data-Structure-Algorithm
Data structures and algorithms

1. Decrementing loops are faster than incrementing loops
For terminating condition processor has direct instruction to compare to zero
	
2. ++i executes faster than i+1
The expression ++i requires a single machine instruction such as INR to carry out the increment operation. 
In case of i+1, apart from INR, other instructions are required to load the value of i. That is why ++i is faster.


Pointers
Dangling Pointer
Wild Pointer


User space and kernel space
User space refers to all code that runs outside the operating system's kernel
Preemptive multitasking
Permits preemption tasks


Process and Threads
Process
Program in execution. A program is a passive entity while a process is an active entity.
Structure of a process in memory is shown in below figure. 



As a process executes, it changes state. The state of a process is defined in part
by the current activity of that process. A process may be in one of the following
states:
• New. The process is being created.
• Running. Instructions are being executed.
• Waiting. The process is waiting for some event to occur (such as an I/O completion or reception of  a signal).
• Ready. The process is waiting to be assigned to a processor.
• Terminated. The process has finished execution.

Process Control Block (PCB)/ Task Control Block

zombie,orphan process

A process that has terminated, but whose parent has not yet called wait(), is known as a zombie process. All processes transition to this state when they terminate, but generally they exist as zombies only briefly. Once the parent calls wait(), the process identifier of the zombie process and its entry in the process table are released.
Now consider what would happen if a parent did not invoke wait() and instead terminated, thereby leaving its child processes as orphans. Linux and UNIX address this scenario by assigning the init process as the new parent to orphan processes.

==> independent,cooperating process

    -> A process is independent if it cannot affect or be affected by the other processes executing in the system. Any process that does not share data with any other process is independent. 
    -> A process is cooperating if it can affect or be affected by the other processes executing in the system.

    -> Cooperating processes require an interprocess communication (IPC) mechanism that will allow them to exchange data and information. 

    There are two fundamental models of interprocess communication: 
    1. shared memory
    2. message passing



Thread
Light weight process.
Process without multiple threads still contains a Main thread.
Reentrant function/code


Compiling and Linking
Steps:

unix> gcc -O2 -g -o p main.c swap.c

C preprocessor translates the C source file into ASCII intermediate file main.i
cpp [other arguments] main.c /tmp/main.i

C compiler main.i into ASCII assembly file main.s
cc1 /tmp/main.i main.c -O2 [other arguments] -o /tmp/main.s

Assembler(as) translates main.s into relocatable object file main.o
as [other arguments] -o /tmp/main.o /tmp/main.s


RTOS
what is priority inversion, how does it happen in RTOS



Misc:

Reentrant vs Thread safe function?

If function is using any static/global data then it is said to be Non reentrant function.

Volatile keyword?
Can a variable be both const and volatile?
What is NULL pointer and what is its use?
What is void pointer and what is its use?
What is size of character, integer, integer pointer, character pointer?
what is virtual function?



Programming Questions


Write a program to test endianess of storage.
Implement strcpy function and show me if there are any limitation of this function. what if the 2 buffers passed to the strcpy function overlaps.
Implement memcpy function.
write a function that determines if a given variable is a power of 2 or not
write a function that count number bits set in a 32 bit integer number.
Delete a node from an XOR-linked list
Find if a linked list is circular or not
Finding a path(Maze problem) 
Deep copy a binary search tree 
Delete an item in a LinkedList




 

3. What kind of data structure would you use to store data from a serial receive line?
 A queue (First in, First out [FIFO])

What is interrupt latency, race condition, context switch
Mutexes, Semaphores, RTOS concepts, Deadlocking

Nvidia
Low level: I can only speak on concepts because they weren't Leetcode. Basically, imagine implementing things like stacks, queues, linkeded lists, and vectors using C only. Know the ins and outs of memory safety. How the stack and heap work with the OS.

I got asked to describe shared memory in relation to the Linux Kernel.
I got asked the many details surrounding synchronization of threads and processes. How/why/etc.

C++:
https://leetcode.com/problems/meeting-rooms-ii/
https://leetcode.com/problems/unique-paths/
You need to know the concepts behind the math solution - not the exact implementation. Basically like, at each step we are choosing to go down or right, we have x/y decisions. Mention permutations.
https://leetcode.com/problems/min-stack/
https://leetcode.com/problems/design-linked-list/




	Bit manipulation

1. 	Count the number of set bits in an integer.
-->
	int noOfSetBits(int n)
	{
		int count =0;
		while(n)
		{
			n = (n & (n-1));
			count++;
		}

		return count;
	}
	
2.  C program to reverse an 8 bit type
--> 
	#include <stdio.h>
	#define CHAR_BIT 8
	int main()
	{
		unsigned int v=0x01;     	// input bits to be reversed
		unsigned int r = v & 1; 	// r will be reversed bits of v; first get LSB of v
		int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end
		printf("%x\n",v);
		for (v >>= 1; v; v >>= 1)
		{   
			printf("%x\n",v);
			r <<= 1;
			r |= v & 1;
			s--;
			printf("%x\n",r);
		}
		r <<= s; // shift when v's highest bits are zero
	}	
	
3.  Write a function that determines if a given variable is a power of 2 or not	
4.  Write a C program to encode bits in a 32-bit number such that, 
	most significant 16 bits should be reversed but lower 16 bits should be untouched. 
5.	Write a function which takes the bit number of an integer as argument and toggles it.	
	
	
	Array
	
1. 	Second was to find maximum sum sub-array of input array. 	
2. 	Search in rotated sorted array
3. 	Problem was to create an array from one input array where every element in 
	output array is the next biggest element from that element.
	
	String
	
1.  Reverse a string 
2. 	Reverse words in a string
3.  Find duplicates in a string 
4. 	Is palindrome?
5.  Given two strings are anagram
6.  Find the first non-recurring character in a string. i.e. input "abbcdcaea" 
	would return "d"  
7.  Return the most frequent character in a string
8.	Write a program to remove duplicates continous characters in a string?	
	
	Linked List
	
1.  Find mid point of a linked list
2.  Delete a node from given linked List
3.  Delete a given linked list 
4. 	Write code to find a point where two linked lists meet
5. 	Merge k sorted linked list
6.  Detect loops in linked list
7. 	Reverse a linked list

	Matrix

1. 	There is a N*M matrix where each row is sorted. Find the kth largest element 
	in matrix? 

	Tree

1. 	Find if a given binary tree is BST.
2. 	Given a BST, find k-th largest element with using extra space.   
3. 	Given a BST, find k-th largest element without using extra space. 

	Graph	
	
1. 	Do the bfs of a graph  
2. 	Given a graph, find out if it can be colored using 2 colors. 
	Different colors for alternate nodes  (BFS)

	C++

1. 	What is the difference between class and object? Does class or object create memory?
-> Class is a like footprint, declaring a class doesnt allocate any memory.
But making an object of that class actually allocates memory.
In other words a class declaration is creating a customized data type.

1. 	Virtual destructor
-> Virtual destructors are useful when you can delete an instance of a derived class through a pointer to base class

2. 	Virtual inheritance
-> Virtual inheritance is a C++ technique that ensures only one copy of a base class's member variables are inherited by grandchild derived classes.
Diamond problem

3. 	Pure virtual classes or Pure virtual function
-> A pure virtual function or pure virtual method is a virtual function that is required to be implemented by a derived class if the derived class is not abstract. 

4. Abstract class
-> Class containing at least one pure virtual function

6. 	Implement typedef operator (function template can be used to write a generic function)
7. 	what is the difference between structures and classes in cpp
-> In cpp class default access specifier is private, in structure it is public

8.  Describe Inheritance
-> Derive a class from base class

	C
	
1. 	my_sizeof implementation
	1. #define my_sizeof(type) (char*)(&type+1)-(char *)(&type)
	2. size_t size = (size_t)(1 + ((X*)0));
	
2. 	Storage classes in C
-->
	auto
    register
    static
    extern
    typedef (sometimes consider as storage class becuase of syntax used)
			
3.  What does appending 'static' to a global variable/function do?	
--> Limits the scope of that variable/function to that source file only.
	If in the project we have multiple source files,then you can have same name
	variable/function in other source file provided the earlier declared one is static.

4.  Swap the values of two pointers without a temp variable  
--> *a = *a ^ *b;
    *b = *a ^ *b;
	*a = *a ^ *b;

5.  Difference between malloc and calloc  	
--> 

6.  const pointers and pointers to const*
7. 	What is static keyword
--> 1. static variable inside a function retains it value.
    2. 

8. 	What is volatile keyword
--> Dont cache this variable, all time consult memory for this variable.

10. What are dangling pointers? 
-->
	A pointer pointing to a memory location that has been deleted (or freed) is called dangling pointer.
	
	ex.	
	int *ptr = (int *)malloc(SIZE);
    free(ptr);
	
	ptr is dangling pointer as it is pointing to same old memory which is already free
	
	ptr = NULL; // Good practice No more dangling
	
11. What are Wild Pointers?
--> 	
	Uninitialized pointers are known as wild pointers because they point 
	to some arbitrary memory location and may cause a program to crash

12. What is the difference between structures and unions? when to use what? sizes?
--> 

13. What is free()? how does free know how much memory to de-allocate?
--> When you call malloc(), you specify the amount of memory to allocate. 
	The amount of memory actually used is slightly more than this, and includes 
	extra information that records (at least) how big the block is. 
	You can't (reliably) access that other information and nor should you.

	When you call free(), it simply looks at the extra information to find out 
	how big the block is.
	
-> A structure cannot contain a member of its own type because if this is allowed  	then it becomes impossible for compiler to know size of such struct. Although a pointer of same type can be a member because pointers of all types are of same size and compiler can calculate size of struct

-> In C, struct and union types cannot have static members
-> In C, struct we cannot initialize values as it is not a variable declaration but a data type declaration. 
-> 
	Data structure and Algorithm

1. 	Dijkstra’s Algorithm, pseudo code- why Dijkstra’s algo fails when 
	-ve weights are there in the graph.
2. 	Find the loop in the graph if it exist and print the 
	nodes of the loop in sorted order.  
3.  Design LRU system
4. 	Min heap  
5. 	Binary search  
6. 	Print sum of all prime numbers within a given range. 
7.  Find the degrees between the minute hand and hour hand when a clock is at 3:15 
8.  Sudoku solver
9.  Write code in C that would hash a string and deal with collision resolution by implementing 
	a linked list. Would this code be thread safe?
	
16. One was to output the decimal number after inverting the binary 
	representation of input number. 

	Operating system + RTOS + Computer Architecture

1. 	What is Virtual Memory 

2. 	Caches 
-> caches the currently used data and other data based on spatial locality and temporal locality
3. 	What is Priority inversion (RTOS)
--> If the High priority task is blocked till the resource got free. 
	which is acquired by low priority task and if any middle priority 
	task becomes ready then it will preempt the low priority task.
	So middle priority got chance to run evenif high priority ready task is pending.
	This situation is called priority inversion.

	Solution is to use Priority inheritance.
	Task acuiring blocking the resource(who got the lock), gets the priority level 
	of highest priority task pending for that resource. 

4. 	What is Reentrancy
-> In computing, a computer program or subroutine is called reentrant if it can be    interrupted in the middle of its execution, and then be safely called again ("re-entered") before its previous invocations complete execution.

5. 	Semaphore vs Mutex vs Spinlocks
	
5. 	What is spinlock ? why it is a bad idea to use spinlock on uniprocessor system?
--> On a uniprocessor, it will either immediately acquire the lock or it will 
	spin forever - if the lock is contended, then there will never be an opportunity 
	for the process which currently holds the resource to give it up. 
	Spinlocks are only useful when another process can execute while one is 
	spinning on the lock - which means multiprocessor systems.
	
6. 	What is Concurrency and Multithreading

7. 	Watchdog Timer

8. 	How post increment works.

9. 	assembly implementation of spinlock?
10. How does a debugger work? 
11. How do breakpoints in a C program works?
-> 
12. How are interrupts handled in RTOS?
--> Application code execution is interrupted (delayed) during the execution 
	of an ISR, most applications minimize the amount of code in the ISR and rely instead 
	on non-ISR code (an application “Thread” or “Task”) to complete the processing. 
	This allows the highest priority application code to be executed as quickly as possible, 
	and delayed as little as possible, even in situations with intense interrupt activity.
	
13. What is atomic programming/non-locking operation?

14. What is trashing? what happens during trashing? what is excessive paging?
-> constant state of paging, rapidly exchanging data in memory for data on disk,
'productive' work less, and 'swapping' more
In virtual memory systems, thrashing may be caused by programs or workloads that present insufficient locality of reference

15. big endian vs little endian, how to find
-->
	#include <stdio.h>
	int main() 
	{
	   unsigned int i = 1;
	   char *c = (char*)&i;
	   if (*c)    
		   printf("Little endian");
	   else
		   printf("Big endian");
	   getchar();
	   return 0;
	}
	
16. What is dynamic loading? what is static loading? when to use dynamic loading? 
	What are the advantages? give an example when to use dynamic loading?
->	Load a library runtime

17. What are interrupts and if you have less external interrupt pins on a processor,  how to interface multiple interrupts?

18. Difference between & and &&
-> '&' is bitwise AND operator,For operands of integer types,it'll calculate the    	bitwise-AND 
   '&&' logical AND operator, 
   
19.	Process address space,Memory regions like stack, heap, text, data segments. 	
-> 	
	Design questions
	
1. 	Design an elevator system
2. 	Desing an LRU(Least recently use) system
3. 	Are there any problems (from a embedded system point of view) you should prevent
	and how will you prevent it in your design  
4.  Write a program to create circular queue
5.  Design a Stack class (pop,push,top,size,getMin)
6.  Implement strcpy function, what if the 2 buffers passed to the strcpy function overlaps ?
7.	Implement aligned malloc
8.  Implement memcpy function with two void pointers and size
9.  Implement a queue/fifo with push/pop functionality using linked lists  

	Brain teasers

1. 	About seating in an airplane. Probability that last person gets a 
	correct seat. 
--> 1/2 


1. How mutex and condition variable works?
-->
	A thread obtains a mutex (condition variables always have an
	associated mutex) and tests the condition under the mutex’s protection. 
	No other thread should alter any aspect of the condition without holding the mutex. 
	If the condition is true, your thread completes its task, releasing the mutex when
	appropriate. 
	If the condition isn’t true, the mutex is released for you, and your thread goes 
	to sleep on the condition variable. 
	When some other thread changes some aspect of the condition, it calls
	pthread_cond_signal(), waking up one sleeping thread. 
	Your thread then reacquires the mutex, reevaluates the condition, and either 
	succeeds or goes back to sleep, depending upon the outcome. 
	You must reevaluate the condition! 
	First,the other thread may not have tested the complete condition before sending 
	the wakeup. 
	Second, even if the condition was true when the signal was sent, it could
	have changed before your thread got to run. 
	Third, condition variables allow for spurious wakeups. 
	They are allowed to wakeup for no discernible reason whatsoever!
	
	
Not all pages are candidates for swapping. Consider kernel code that responds to 
interrupts or code that manages the page tables and swap logic. These are obvious 
pages that should never be swapped out and are therefore pinned, or permanently 
resident in memory. 
Although kernel pages are not candidates for swapping, user space pages are, 
but they can be pinned through the mlock (or mlockall) function  to lock the page down. 
This is the purpose behind the user space memory access functions. 

Linux Programming

1. 	Why we need copy_from_user(as kernel already has access to user space memory)
--> If the kernel assumed that an address that a user passed was valid and 
	accessible, a kernel panic would eventually occur (for example, because the user 
	page was swapped out, resulting in a page fault in the kernel). 
	This application programming interface (API) ensures that those corner cases are 
	handled properly.
	
	
int strCmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}


Splay Tree:
http://www.geeksforgeeks.org/splay-tree-set-1-insert/
http://www.geeksforgeeks.org/avl-tree-set-1-insertion/


1. Write a function that returns lowest possible number that can be generated after removing n characters.



JTAG
The connector pins are
TDI (Test Data In)
TDO (Test Data Out)
TCK (Test Clock)
TMS (Test Mode Select)
TRST (Test Reset) optional
