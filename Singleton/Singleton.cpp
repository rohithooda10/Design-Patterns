#include <iostream>
#include <mutex>
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
    mutex mtx;
public:
    Logger* createLogger()
    {
        // double checking lock - for multithreading
        if(logger == NULL)
        {
            // lock()
            lock_guard<mutex> lock(mtx);
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