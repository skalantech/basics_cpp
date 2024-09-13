#include <iostream>

class Log
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;
private:
    int m_logLevel = LogLevelInfo;
public:
    void SetLevel(int level)
    {
        m_logLevel = level;
    }

    void Error(const char* message)
    {
        if (m_logLevel >= LogLevelError)
        {
            std::cout << "[ERROR]: " << message << '\n';
        }
    }

    void Warn(const char* message)
    {
        if (m_logLevel >= LogLevelWarning)
        {
            std::cout << "[WARNING]: " << message << '\n';
        }
    }

    void Info(const char* message)
    {
        if (m_logLevel >= LogLevelInfo)
        {
            std::cout << "[INFO]: " << message << '\n';
        }
    }
};

int main()
{
    Log log;
    log.SetLevel(log.LogLevelInfo);
    log.Warn("Yo this a Warning");
    log.Error("What's up Error");
    log.Info("Just an Info");

    std::cin.get();
    return 0;
}