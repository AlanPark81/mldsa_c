set(LIB_SOURCES linkedlist.c queue.c qsort.c)

set(MAIN_SOURCES main.c)

set(HEADERS 
  ${CONFIG_HEADER}
        linkedlist.h
        queue.h
        qsort.h)

add_library(mldsa_c STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main mldsa_c)

install(TARGETS mldsa_c
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/linkedlist.h DESTINATION include)
