#include <iostream>
#include <stdio.h>
#include <fstream>
#include <chrono>
//#include <thread>
using namespace std;
double current,previous = 0.0;
double interval = 1.0;


int main()
{
    
    fstream plikZapis;
    plikZapis.open("plik.csv",ios::out | ios::trunc);
            if (plikZapis.is_open())
            {
                plikZapis << "TIME" << "\n";
                plikZapis.close();
            } else return -1;
    
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
            //wykonuj operacje co interval
            printf("\a");
            plikZapis.open("plik.csv",ios::app);
            if (plikZapis.is_open())
            {
                plikZapis << current << "\n";
                plikZapis.close();
            }
            
            
            
            
            previous = current;
        }
    }


return 0;
}
