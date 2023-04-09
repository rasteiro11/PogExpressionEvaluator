project(MathematicalExpressionTokenizedHandler)

add_library(lexicon ./lexicon/lexicon.cpp)
add_library(token ./token/token.cpp ./token/token_record.cpp) 

add_executable(METH main.cpp)

target_link_libraries(METH PRIVATE lexicon token)
