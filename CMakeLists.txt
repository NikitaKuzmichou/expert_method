﻿cmake_minimum_required (VERSION 3.17)

project ("expert_method")

add_subdirectory (src)
add_executable (expert_method  app/expert_method.cpp)
target_link_libraries (expert_method PUBLIC MathematicLib ExpertMethodLib LabLogicLib)
install (TARGETS expert_method DESTINATION bin)
