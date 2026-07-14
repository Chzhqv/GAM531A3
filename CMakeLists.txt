cmake_minimum_required(VERSION 3.15)
project(GAM531A3 CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# --- Dependencies fetched at configure time -------------------------------
include(FetchContent)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4
    GIT_SHALLOW    TRUE
)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        1.0.1
    GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(glfw glm)

# --- GLAD (vendored, generated for OpenGL 3.3 core) -----------------------
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)
target_link_libraries(glad PUBLIC ${CMAKE_DL_LIBS})

# --- stb_image (vendored, header-only) -------------------------------------
add_library(stb_image STATIC external/stb/stb_image_impl.cpp)
target_include_directories(stb_image PUBLIC external/stb)

# --- Main application --------------------------------------------------
add_executable(GAM531A3
    src/main.cpp
    src/Shader.cpp
    src/Texture.cpp
)

target_include_directories(GAM531A3 PRIVATE src)
target_link_libraries(GAM531A3 PRIVATE glad stb_image glfw glm::glm)

if (WIN32)
    target_link_libraries(GAM531A3 PRIVATE opengl32)
elseif (APPLE)
    target_link_libraries(GAM531A3 PRIVATE "-framework OpenGL")
else()
    target_link_libraries(GAM531A3 PRIVATE GL)
endif()

# Copy shaders next to the built executable so relative paths work at runtime
add_custom_command(TARGET GAM531A3 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:GAM531A3>/shaders
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:GAM531A3>/assets
)
