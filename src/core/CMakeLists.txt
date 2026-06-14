# --- SOURCE FILES --- #
# Whatever is needed for this library's build as a variable
set(CORE_SOURCES 
	server.cpp
)

# Static library (.a file) ~ pre-compiled bundle that will be copied into final executable
# if included. "create a library *target* called server_core USING core_sources
add_library(server_core STATIC ${CORE_SOURCES})

# if any consumer wants to use this library OR when I am compiling this lib, 
# I and they should know this library (server_core)'s
# header files ("the user manual") are located at "XYZ"

target_include_directories(server_core PUBLIC ${PROJECT_SOURCE_DIR}/include/)
