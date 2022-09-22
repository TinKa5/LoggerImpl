#pragma once

#include "Logger.h"

class Test
{
public: 
	void testLogger() {
		*Logger::getLogger() << "Write to log from test class";
	}
};

