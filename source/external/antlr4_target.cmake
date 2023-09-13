find_package(Java 11.0 COMPONENTS Runtime REQUIRED)

file(DOWNLOAD https://www.antlr.org/download/antlr-4.13.0-complete.jar
    "${CMAKE_CURRENT_BINARY_DIR}/antlr4/antlr-4.13.0-complete.jar"
    EXPECTED_HASH SHA256=bc6f4abc0d225a27570126c51402569f000a8deda3487b70e7642840e570e4a6
    )

find_program(ANTLR_EXECUTABLE
    NAMES antlr-4.13.0-complete.jar
    PATHS "${CMAKE_CURRENT_BINARY_DIR}/antlr4/"
    REQUIRED)

macro(ANTLR_TARGET Name InputFile)
set(ANTLR_OPTIONS LEXER PARSER LISTENER VISITOR)
set(ANTLR_ONE_VALUE_ARGS PACKAGE OUTPUT_DIRECTORY DEPENDS_ANTLR)
set(ANTLR_MULTI_VALUE_ARGS COMPILE_FLAGS DEPENDS)
cmake_parse_arguments(ANTLR_TARGET
                        "${ANTLR_OPTIONS}"
                        "${ANTLR_ONE_VALUE_ARGS}"
                        "${ANTLR_MULTI_VALUE_ARGS}"
                        ${ARGN})

get_filename_component(AbsoluteInputFile "${InputFile}" ABSOLUTE)
set(ANTLR_${Name}_INPUT ${AbsoluteInputFile})

get_filename_component(ANTLR_INPUT ${InputFile} NAME_WE)

if(ANTLR_TARGET_OUTPUT_DIRECTORY)
    set(ANTLR_${Name}_OUTPUT_DIR ${ANTLR_TARGET_OUTPUT_DIRECTORY})
else()
    set(ANTLR_${Name}_OUTPUT_DIR
        ${CMAKE_CURRENT_BINARY_DIR}/antlr4cpp_generated_src/${ANTLR_INPUT})
endif()

unset(ANTLR_${Name}_CXX_OUTPUTS)

if((ANTLR_TARGET_LEXER AND NOT ANTLR_TARGET_PARSER) OR
    (ANTLR_TARGET_PARSER AND NOT ANTLR_TARGET_LEXER))
    list(APPEND ANTLR_${Name}_CXX_OUTPUTS
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}.h
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}.cpp)
    set(ANTLR_${Name}_OUTPUTS
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}.interp
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}.tokens)
else()
    list(APPEND ANTLR_${Name}_CXX_OUTPUTS
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}Lexer.h
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}Lexer.cpp
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}Parser.h
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}Parser.cpp)
    list(APPEND ANTLR_${Name}_OUTPUTS
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}Lexer.interp
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}Lexer.tokens)
endif()

if(ANTLR_TARGET_LISTENER)
    list(APPEND ANTLR_${Name}_CXX_OUTPUTS
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}BaseListener.h
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}BaseListener.cpp
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}Listener.h
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}Listener.cpp)
    list(APPEND ANTLR_TARGET_COMPILE_FLAGS -listener)
endif()

if(ANTLR_TARGET_VISITOR)
    list(APPEND ANTLR_${Name}_CXX_OUTPUTS
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}BaseVisitor.h
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}BaseVisitor.cpp
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}Visitor.h
        ${ANTLR_${Name}_OUTPUT_DIR}/${ANTLR_INPUT}Visitor.cpp)
    list(APPEND ANTLR_TARGET_COMPILE_FLAGS -visitor)
endif()

if(ANTLR_TARGET_PACKAGE)
    list(APPEND ANTLR_TARGET_COMPILE_FLAGS -package ${ANTLR_TARGET_PACKAGE})
endif()

list(APPEND ANTLR_${Name}_OUTPUTS ${ANTLR_${Name}_CXX_OUTPUTS})

if(ANTLR_TARGET_DEPENDS_ANTLR)
    if(ANTLR_${ANTLR_TARGET_DEPENDS_ANTLR}_INPUT)
    list(APPEND ANTLR_TARGET_DEPENDS ${ANTLR_${ANTLR_TARGET_DEPENDS_ANTLR}_OUTPUTS})
    list(APPEND ANTLR_TARGET_COMPILE_FLAGS -lib ${ANTLR_${ANTLR_TARGET_DEPENDS_ANTLR}_OUTPUT_DIR})
    else()
    message(SEND_ERROR
            "ANTLR target '${ANTLR_TARGET_DEPENDS_ANTLR}' not found")
    endif()
endif()

add_custom_command(
    OUTPUT ${ANTLR_${Name}_OUTPUTS}
    COMMAND ${Java_JAVA_EXECUTABLE} -jar ${ANTLR_EXECUTABLE}
            ${AbsoluteInputFile}
            -o ${ANTLR_${Name}_OUTPUT_DIR}
            -no-listener
            -Dlanguage=Cpp
            ${ANTLR_TARGET_COMPILE_FLAGS}
    DEPENDS ${InputFile}
            ${ANTLR_TARGET_DEPENDS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building ${Name} with ANTLR")
endmacro(ANTLR_TARGET)
