#include "../includes/logging.h"
#include <iostream>
using namespace std;
#include "../includes/errorType.h"

logging* logging::getInstance()
    {
        if(loggingInstance == nullptr)
        {
            loggingInstance = new logging();
            
        }
        return loggingInstance;
    }

logging::~logging()
{
}


error_type_t logging::log(message_type_t msg_type, char* message) 
{
    if((int)(msg_type) >= (int)(this->loggingInstance->logLevel))
    {
        cout << message << endl;
    }
    return Success;

}

error_type_t logging::setLogLevel(log_level_type_t level)
{
    this->loggingInstance->logLevel = (log_level_type_t)level;
    return Success;
}