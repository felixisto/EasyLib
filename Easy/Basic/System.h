#pragma once

#include "Defines.h"
#include <chrono>
#include <thread>

namespace easy {
	namespace system {
        static void sleep(real seconds)
        {
            auto time = std::chrono::duration<double>(seconds);
            std::this_thread::sleep_for(time);
        }
	};
};
