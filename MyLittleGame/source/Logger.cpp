#include "Logger.h"
std::ostream& mlg::Logger::getLogger() {
	return std::cout;
}