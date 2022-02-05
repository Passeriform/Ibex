#pragma once

#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <functional>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// TODO: Sort imports. Use only required and purge extreneous.

using GLFWwindowDeleter = std::function<void(GLFWwindow*)>;
extern GLFWwindowDeleter defaultWindowDeleter;
extern GLFWwindowDeleter emptyWindowDeleter;

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

template <typename T>
using scope_marker = std::unique_ptr<T, std::function<void(T*)>>;

template <typename T>
scope_marker<T> with_context(std::function<T()> ctor, std::function<void()> _dtor) {
	decltype(_dtor)* dtor = new decltype(_dtor)(_dtor);
	scope_marker<T> marker(new bool(ctor()), [dtor](bool* mark) { (*dtor)(); });
	return std::move(marker);
}

void run_contextually(std::function<void()> ctor, std::function<void()> dtor, std::function<void()> delegate);

#endif
