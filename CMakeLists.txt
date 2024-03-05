add_executable(trap_rain_water dynamic_programming/trap_rain_water.cpp)

set_target_properties(trap_rain_water PROPERTIES COMPILE_FLAGS "-std=c++17")

add_executable(course_schedule graph/course_schedule.cpp)

set_target_properties(course_schedule PROPERTIES COMPILE_FLAGS "-std=c++17")

add_executable(min_height_tree graph/minimum_height_tree.cpp)

set_target_properties(min_height_tree PROPERTIES COMPILE_FLAGS "-std=c++17")

add_executable(provinces graph/provinces.cpp)

set_target_properties(provinces PROPERTIES COMPILE_FLAGS "-std=c++17")

add_executable(redundant_connections graph/redundant_connections.cpp)

set_target_properties(redundant_connections PROPERTIES COMPILE_FLAGS "-std=c++17")

add_executable(evaluate_division graph/evaluate_division.cpp)

set_target_properties(evaluate_division PROPERTIES COMPILE_FLAGS "-std=c++17")

add_executable(is_bipartite graph/is_bipartite.cpp)

set_target_properties(is_bipartite PROPERTIES COMPILE_FLAGS "-std=c++17")

add_executable(cheapest_flights graph/cheapest_flights.cpp)

set_target_properties(cheapest_flights PROPERTIES COMPILE_FLAGS "-std=c++17")

add_executable(average dynamic_programming/product_linear.cpp)

set_target_properties(average PROPERTIES COMPILE_FLAGS "-std=c++17")

add_executable(average_submitted dynamic_programming/product_linear_submitted.cpp
        dynamic_programming/product_linear_submitted.cpp)

set_target_properties(average_submitted PROPERTIES COMPILE_FLAGS "-std=c++17")