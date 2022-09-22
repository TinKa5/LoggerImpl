#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Logger
{
protected:
	Logger() {
		stream_ = &cout;
	}
	Logger(string filename) : is_file(true) {
		ofstream* of = new ofstream(filename);
		if (!of->is_open()) {
			throw exception("Exceptionn during opening log file");
		}
		*of << "LOG FILe\n";
		stream_ = of;
	}

	static Logger* instance;

	ostream* stream_;
	bool is_file;

public:
	Logger(Logger& log) = delete;
	void operator=(const Logger&) = delete;

	static Logger* getLogger() {
		if (instance == nullptr) {
			instance = new Logger();
		}
		return instance;
	}	

	static Logger* getLogger(std::string filename) {
		if (instance == nullptr) {
			instance = new Logger(filename);
		}
		return instance;
	}

	void log(const string msg) {
		*stream_ << '\n' + msg + '\n';
	}

	Logger* operator <<(const string msg) {
		log(msg);
		return instance;
	}

	~Logger() {
		if (is_file) {
			((ofstream*)stream_)->close();
			delete stream_;
		}
	}

};

