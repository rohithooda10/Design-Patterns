#include <iostream>
using namespace std;

// Product
class Logger{
    string loggerType;
    string timeframe;
public:
    Logger()
    {
        loggerType = "InfoLogger";
        timeframe = "Past year";
    }
    void display()
    {
        cout<<"Logger type: "<<loggerType<<endl;
        cout<<"Time frame: "<<timeframe<<endl;
    }
};

// Singleton class
class LoggerSingleton{
    Logger* logger;
public:
    Logger* createLogger()
    {
        // double checking lock - for multithreading
        if(logger == NULL)
        {
            // lock()
            if(logger == NULL)
                logger = new Logger();
            // unlock()
        }
        return logger;
    }
};
int main() {
    LoggerSingleton* loggerSingleton = new LoggerSingleton();
    Logger* logger = loggerSingleton->createLogger();
    logger->display();
}