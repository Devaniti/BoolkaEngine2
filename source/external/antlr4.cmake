include(ExternalProject)

set(ANTLR4_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/antlr4")
set(ANTLR4_INSTALL_PATH "${CMAKE_CURRENT_BINARY_DIR}/antlr4_runtime")
set(ANTLR4_INCLUDE_DIR "${ANTLR4_INSTALL_PATH}/include/antlr4-runtime")

if(WIN32)
    set(ANTLR4_STATIC_LIBRARY
        "${ANTLR4_INSTALL_PATH}/lib/antlr4-runtime-static.lib")
else()
    set(ANTLR4_STATIC_LIBRARY
        "${ANTLR4_INSTALL_PATH}/lib/libantlr4-runtime.a")
endif()

file(MAKE_DIRECTORY "${ANTLR4_INCLUDE_DIR}")

ExternalProject_Add(
    antlr4_runtime
    PREFIX antlr4_runtime
    SOURCE_DIR ${ANTLR4_ROOT}
    SOURCE_SUBDIR runtime/Cpp
    BYPRODUCTS ${ANTLR4_STATIC_LIBRARY}
    CMAKE_CACHE_ARGS
        -DCMAKE_BUILD_TYPE:STRING=$<CONFIG>
        -DWITH_STATIC_CRT:BOOL=OFF
        -DDISABLE_WARNINGS:BOOL=ON
        -DCMAKE_INSTALL_PREFIX:STRING=${ANTLR4_INSTALL_PATH}
        -DWITH_DEMO:BOOL=OFF
        -DANTLR_BUILD_CPP_TESTS:BOOL=OFF
        -DANTLR_BUILD_SHARED:BOOL=OFF
        -DANTLR_BUILD_STATIC:BOOL=ON
    EXCLUDE_FROM_ALL TRUE)

ExternalProject_Get_Property(antlr4_runtime install_dir)

set(ANTLR4_INSTALL_DIR "${install_dir}")

add_library(antlr4_static STATIC IMPORTED GLOBAL)
add_dependencies(antlr4_static antlr4_runtime)
set_target_properties(antlr4_static PROPERTIES
                      IMPORTED_LOCATION "${ANTLR4_STATIC_LIBRARY}")
target_include_directories(antlr4_static INTERFACE "${ANTLR4_INCLUDE_DIR}")
target_compile_definitions(antlr4_static INTERFACE "ANTLR4CPP_STATIC")
get_property(int_includes TARGET antlr4_static PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "Interface includes")
message(STATUS "${int_includes}")
