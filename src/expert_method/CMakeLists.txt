cmake_minimum_required (VERSION 3.17)

add_library (ExpertMethod 
             STATIC
                WeightsStorage.cpp
                WeightsService.cpp "CompetenceResolver.cpp")