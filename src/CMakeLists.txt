project(quiz)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract(quiz quiz quiz.cpp)
target_include_directories(quiz PUBLIC ${CMAKE_SOURCE_DIR}/../include)
