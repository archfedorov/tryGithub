#include "Constants.h"

using namespace mlg;

std::map<std::string, float> Constants::floats = {};
std::map<std::string, int> Constants::ints = {};

float Constants::getFloat(const std::string& key) {
	return floats[key];
}
void Constants::setFloat(const std::string& key, const float& value) {
	floats[key] = value;
}
float Constants::getInt(const std::string& key) {
	return ints[key];
}
void Constants::setInt(const std::string& key, const int& value) {
	ints[key] = value;
}
