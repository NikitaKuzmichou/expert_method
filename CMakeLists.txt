cmake_minimum_required (VERSION 3.17)

project ("expert_method")

add_subdirectory (src)
add_executable (expert_method  app/expert_method.cpp "include/expert_method/competence/CompetenceResolver.hpp" )
target_link_libraries (expert_method PUBLIC MathematicLib ExpertMethod)
install (TARGETS expert_method DESTINATION bin)
