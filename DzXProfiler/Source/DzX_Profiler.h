#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <fstream>

#include <thread>

//Struct to contain basic result info
struct ProfileResult
{
    std::string Name;
    long long Start, End;
    uint32_t  ThreadID;
};

//Session name
struct InstrumentationSession
{
    std::string Name;
};
//Write down json file for chrome://trace
class Instrumentor
{
private:
    //Current session
    InstrumentationSession* m_CurrentSession;
    //Session content
    std::ofstream m_OutputStream;
    //Current profile, to divide segments
    int m_ProfileCount;
public:
    //Constructor
    Instrumentor();
     
    //Start write session, construct file to write in
    void BeginSession(const std::string& name, const std::string& filepath = "results.json");

    //Finish session, write footer, close session
    void EndSession();
    //Write content of profiler inside the JSON file
    void WriteProfile(const ProfileResult& result);
    //Write header only for JSON file
    void WriteHeader();
    //Write footer only for JSON file
    void WriteFooter();

    //Getter for an instance of this class
    static Instrumentor& Get() 
    {
        static Instrumentor instance;
        return instance;
    };
};
//Measuring function performance
class Timer
{
public:
    //Constructor
    Timer(const char* Name);
    //Destructor
    ~Timer();

private:
    //Timer name
	const char* m_TimerName;
    //Timer start time
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
	//Is timer running or not
    bool m_bIsStopped;

public:
    //Finish/stop timer
    void Stop();


};
