#pragma once
#include <map>
#include <string>

namespace mlg {
	
	class Constants {
	public:
		static float getFloat(const std::string& key);
		static void setFloat(const std::string& key, const float& value);
		static float getInt(const std::string& key);
		static void setInt(const std::string& key, const int& value);
	private:
		static std::map<std::string, float> floats;
		static std::map<std::string, int> ints;
	};
}