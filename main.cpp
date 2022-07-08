#include <iostream>
#include <stdio.h>
#include <fstream>
#include <chrono>
//#include <thread>
double current,previous = 0.0;
double interval = 1.0;


int main()
{
    
    
    std::chrono::duration<double> elapsed_seconds;
    auto start = std::chrono::high_resolution_clock::now();
    
    while (1)
    {
        auto end = std::chrono::high_resolution_clock::now();   
        elapsed_seconds = end-start;
        printf("uplynelo:%.3f s\r",elapsed_seconds.count());
        current = elapsed_seconds.count();
        
        if (current - previous >= interval)
        {
            printf("\a");
            previous = current;
        }
    }


return 0;
}
