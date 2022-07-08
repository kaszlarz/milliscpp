#include <iostream>
#include <stdio.h>
#include <fstream>
#include <chrono>
#include <linux/kernel.h>
#include <sys/sysinfo.h>

//#include <thread>
using namespace std;
double current,previous = 0.0;
double interval = 1.0; //0.05 50ms


int main(int argc, char** argv)
{
    const double mb=1024*1024;
    const float load_avg_sysinfo_scale = 2<<16;

    struct sysinfo s;
    //sysinfo (&s);



    fstream plikZapis;
    plikZapis.open("plik.csv",ios::out | ios::trunc);
            if (plikZapis.is_open())
            {
                plikZapis << "TIME,Load1,Load5,Load15,FreeRAM" << "\n";
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
             sysinfo (&s);
            printf("\a");
            plikZapis.open("plik.csv",ios::app);
            if (plikZapis.is_open())
            {
                plikZapis << current << ","<< s.loads[0]/load_avg_sysinfo_scale << ","<< s.loads[1]/load_avg_sysinfo_scale << "," << s.loads[2]/load_avg_sysinfo_scale << "," << (s.freeram/mb) <<"\n";
                plikZapis.close();
            }
            
            
            
            
            previous = current;
        }
    }


return 0;
}
