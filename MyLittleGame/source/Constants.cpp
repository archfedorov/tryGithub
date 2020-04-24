#include "Constants.h"

using namespace mlg;

std::map<std::string, float> Constants::floats = {};
std::map<std::string, int> Constants::ints = {};
std::map<std::string, bool> Constants::bools = {};

float Constants::getFloat(const std::string& key) {
	return floats[key];
}
void Constants::setFloat(const std::string& key, const float& value) {
	floats[key] = value;
}
int Constants::getInt(const std::string& key) {
	return ints[key];
}
void Constants::setInt(const std::string& key, const int& value) {
	ints[key] = value;
}
bool Constants::getBool(const std::string& key) {
	return bools[key];
}
void Constants::getBool(const std::string& key, const bool& value) {
	bools[key] = value;
}
