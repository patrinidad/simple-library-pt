
set(THREADS_PREFER_PTHREAD_FLAG ON)
set (CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME}-lib STATIC
    file_creator.cpp
)

target_include_directories(${PROJECT_NAME}-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME}
    main.cpp
    file_creator.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
