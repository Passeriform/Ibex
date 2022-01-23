#pragma once

#ifndef UTILITY_H
#define UTILITY_H

#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// TODO: Sort imports. Use only required and purge extreneous.

typedef void(*GLFWwindowDeleter)(GLFWwindow*);
auto windowDeleter = [](GLFWwindow*) {};

template <typename... T>
std::vector<std::tuple_element_t<0, std::tuple<T...>>> construct_inplace_vec_by_move(T&&... rest) {
	std::vector<std::tuple_element_t<0, std::tuple<T...>>> packVec;
	construct_vec_by_move(packVec, std::forward<T>(rest)...);
	return packVec;
}

template <typename T, typename... Ts>
void construct_vec_by_move(std::vector<T>& packVec, T elem, Ts&&... rest) {
	packVec.emplace_back(std::move(elem));
	construct_vec_by_move(packVec, std::forward<Ts>(rest)...);
}

template <typename T>
void construct_vec_by_move(std::vector<T>& packVec, T elem) {
	packVec.emplace_back(std::move(elem));
}

#endif
