# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GerenciadorDeTarefas_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GerenciadorDeTarefas_autogen.dir\\ParseCache.txt"
  "GerenciadorDeTarefas_autogen"
  )
endif()