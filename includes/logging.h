#ifndef LOGGING_H
#define LOGGING_H

#include "errorType.h"



enum log_level_type_t
    {
        DEBUG,
        INFO,
        ERROR,
    };

typedef log_level_type_t message_type_t;


class logging
{
private:
    static logging* loggingInstance;
    log_level_type_t logLevel;

    logging(){}
    

public:
    ~logging();
    logging(const logging& obj) = delete;
    

    static logging* getInstance();

    


    error_type_t log(message_type_t msg_type, char* message);
    error_type_t setLogLevel(message_type_t level);
};


#endif
