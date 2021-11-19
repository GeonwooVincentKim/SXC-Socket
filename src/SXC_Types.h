#pragma once
#include<tuple>

namespace sxc {
	
	template<typename... Types>
	using _pkg = std::tuple<Types...>;

	template<typename... Args>
	constexpr auto _pack(Args...) { return std::make_tuple(Args...); }

}