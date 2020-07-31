#include <iostream>

public class Log {
public:
	// Vars
	enum LogLevel {
		LogError = 0, LogWarning, LogInfo
	};
private:
	LogLevel m_LogLevel;
public:
	// Methods
	void SetLevel(LogLevel level) {
		m_LogLevel = level;
	}

	void Error(const char* message) {
		if (m_LogLevel >= LogError) {
			std::cout << "[ERROR]: " << message << std::endl;
		}
		
	}
	void Info(const char* message) {
		if (m_LogLevel >= LogInfo) {
			std::cout << "[INFO]: " << message << std::endl;
		}

	}
	void Warn(const char* message) {
		if (m_LogLevel >= LogWarning) {
			std::cout << "[WARNING]: " << message << std::endl;
		}
	}

	Log() {
		m_LogLevel = LogInfo;
	}
	Log(Log::LogLevel defaultLogLevel) {
		m_LogLevel = defaultLogLevel;
	}
};

int main() {

	Log log(Log::LogWarning);
	log.Error("Error Test");
	log.Warn("Warn Test");
	log.Info("Info Test");


	return 0;
}