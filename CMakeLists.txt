cmake_minimum_required(VERSION 3.10) # Or a suitable minimum version

# Project Name
project(FFmpegVideoDuration)

# Find FFmpeg 
find_package(FFMPEG REQUIRED)
add_executable(FFmpegVideoDuration main.cpp)
target_include_directories(FFmpegVideoDuration PRIVATE ${FFMPEG_INCLUDE_DIRS})
target_link_directories(FFmpegVideoDuration PRIVATE ${FFMPEG_LIBRARY_DIRS})
target_link_libraries(FFmpegVideoDuration PRIVATE ${FFMPEG_LIBRARIES})
