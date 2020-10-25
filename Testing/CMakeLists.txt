include(CTest)

enable_testing()
file(GLOB TESTS *.cpp *.h)
add_executable(unit_testing ${TESTS})
add_test(UNIT_TESTS unit_testing)
target_link_libraries(unit_testing GUIAPI_TYPES)