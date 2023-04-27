#ifndef LOGGING_H
#define LOGGING_H

#include "errorType.h"

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET_TERMINAL_COLOR   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

enum log_level_type_t
    {
        DEBUG,
        INFO,
        SUCCESS,
        WARNING,
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
