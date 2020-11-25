cmake_minimum_required (VERSION 3.17)

project ("expert_method")

add_subdirectory (src)
add_executable (expert_method  app/expert_method.cpp "include/mathematic/service/MathVectorService.hpp" "include/mathematic/service/MatrixService.hpp" "include/expert_method/weights/WeightsStorage.hpp" "include/expert_method/weights/WeightsService.hpp")
target_link_libraries (expert_method PUBLIC MathematicLib)
install (TARGETS expert_method DESTINATION bin)
