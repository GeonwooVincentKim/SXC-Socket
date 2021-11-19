#pragma once
#include<tuple>

namespace sxc {
	
	template<typename... Types>
	using _pkg = std::tuple<Types...>;

	template<typename... Types>
	constexpr auto _pack(Types&&... Args) { return std::make_tuple(Args...); }

}