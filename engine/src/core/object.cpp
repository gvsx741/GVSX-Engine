#pragma once

#include <vector>
#include <string>
#include <map>
#include <unordered_map>

namespace gvsx {

	namespace core {

		using string = std::string;

		template<typename T>
		using vector = std::vector<T>;

		template<typename T, typename V>
		using map = std::map<T, V>;

		template<typename T, typename V>
		using unordered_map = std::unordered_map<T, V>;
 
	}
}

