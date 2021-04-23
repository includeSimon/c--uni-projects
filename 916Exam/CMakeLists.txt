cmake_minimum_required(VERSION 3.17)
project(916Exam)

set(CMAKE_CXX_STANDARD 14)

add_executable(916Exam main.cpp domain/Gene.cpp domain/Gene.h persistence/Repo.cpp persistence/Repo.h business/GeneService.cpp business/GeneService.h presentation/Console.cpp presentation/Console.h tests/Tests.cpp tests/Tests.h errors/GeneError.cpp errors/GeneError.h errors/RepoError.cpp errors/RepoError.h domain/GeneDTO.cpp domain/GeneDTO.h)