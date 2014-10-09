include_directories(${CMAKEDEMO_SOURCE_DIR}/Participants)
link_directories(${CMAKEDEMO_BINARY_DIR}/Participants)

#the one C file
add_executable(EconomyParticipants EconomyParticipants.cpp)
add_executable(Manufactur Manufactur.cpp)
add_executable(MovingTrader MovingTrader.cpp)
add_executable(Traders Traders.cpp)

foreach(program ${PROGRAMS})
  add_executable(${program} ${program}.cpp)
  target_link_libraries(${program} ${CORELIBS})
endforeach(program)
