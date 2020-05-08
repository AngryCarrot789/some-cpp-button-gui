#pragma once
#include <iostream>

typedef void (*pCallback)(void* e);
typedef void (*Callback)();

// A class that provides basic callback functionality, preferably for 
// calling methods in a parent class from within a child class
class Event
{
public:
    void* Parameters = nullptr;
    Event(pCallback callbackFunction, void* params = nullptr)
    {
        Parameters = params;
        pcallback = callbackFunction;
    }
    Event(Callback callbackFunction)
    {
        Parameters = nullptr;
        callback = callbackFunction;
    }

    void Call()
    {
        if (callback != nullptr && callback != (Callback)4294967294)(*callback)();
        if (pcallback != nullptr && Parameters == nullptr)
            (*pcallback)(Parameters);
    }
private:
    pCallback pcallback;
    Callback callback;
};