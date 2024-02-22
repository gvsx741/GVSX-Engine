#pragma once

#include <core/allocator.h>

#include <vector>
#include <string>
#include <map>
#include <unordered_map>

namespace gvsx {

	namespace core {

		typedef std::basic_string<char, std::char_traits<char>, cAllocator<char>> string;

		template<typename T>
		using vector = std::vector<T, cAllocator<T>>;

		template<typename K, typename T>
		using map = std::map<K, T, std::less<K>, cAllocator<std::pair<const K, T>>>;

		template<typename K, typename V>
		using unordered_map = std::unordered_map<K, V, std::hash<K>, std::equal_to<K>, cAllocator<std::pair<const K, V>>>;
	}
}

