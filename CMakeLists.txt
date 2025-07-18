Cmake_minimum_required(VERSION 3.15)
project(
	TemplateTest
	LANGUAGES CXX)

add_library(TemplateBLib B.hxx)

set_target_properties(TemplateBLib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(TemplateTest main.cxx)

target_link_libraries(TemplateTest PRIVATE TemplateBLib)