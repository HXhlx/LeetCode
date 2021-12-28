project(headers)
aux_source_directory(. HEADERS)
add_library(${PROJECT_NAME} ${HEADERS})