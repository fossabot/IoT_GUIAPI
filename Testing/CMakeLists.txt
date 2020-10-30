# Library array testing
set(ARRAY_TEST_NAME array-test)
add_executable(${ARRAY_TEST_NAME} ${ARRAY_TEST_NAME}.cpp)
target_link_libraries(${ARRAY_TEST_NAME} GUIAPI_TYPES --coverage)
add_test(${ARRAY_TEST_NAME} ${ARRAY_TEST_NAME})

# Library string testing
set(STRING_TEST_NAME string-test)
add_executable(${STRING_TEST_NAME} ${STRING_TEST_NAME}.cpp)
target_link_libraries(${STRING_TEST_NAME} GUIAPI_TYPES --coverage)
add_test(${STRING_TEST_NAME} ${STRING_TEST_NAME})

# Library string and array together testing
set(STRING_TEST_NAME string-array-test)
add_executable(${STRING_TEST_NAME} ${STRING_TEST_NAME}.cpp)
target_link_libraries(${STRING_TEST_NAME} GUIAPI_TYPES --coverage)
add_test(${STRING_TEST_NAME} ${STRING_TEST_NAME})