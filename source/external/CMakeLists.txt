find_package(Java 11 REQUIRED COMPONENTS Runtime)

file(DOWNLOAD https://www.antlr.org/download/antlr-4.13.0-complete.jar
    "${CMAKE_CURRENT_BINARY_DIR}/antlr4/antlr-4.13.0-complete.jar"
    EXPECTED_HASH SHA256=bc6f4abc0d225a27570126c51402569f000a8deda3487b70e7642840e570e4a6
    )

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/antlr4)

find_program(ANTLR_EXECUTABLE
    NAMES antlr-4.13.0-complete.jar
    PATHS "${CMAKE_CURRENT_BINARY_DIR}/antlr4/")

set(ANTLR4_WITH_STATIC_CRT OFF)
set(ANTLR4_TAG 4.13.0)
include(FindANTLR)
include(ExternalAntlr4Cpp)
find_package(ANTLR REQUIRED)
