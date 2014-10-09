include_directories(${CMAKEDEMO_SOURCE_DIR}/World)
link_directories(${CMAKEDEMO_BINARY_DIR}/World)

#the one C file
add_executable(world world.cpp)


foreach(program ${PROGRAMS})
  add_executable(${program} ${program}.cpp)
  target_link_libraries(${program} ${CORELIBS})
endforeach(program)
