# 設定建置專案所需的最低 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 定義專案名稱和版本
project(wasm-demo VERSION 1.0)

# 設定建置類型為 release 模式
set(CMAKE_BUILD_TYPE release)

# 指定 C++ 標準版本
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 設定 OpenCV 函式庫的路徑，這是為 WebAssembly 建置的版本
set(OpenCV_DIR "~/Project/Lib/opencv_setup/build_wasm")
find_package(OpenCV REQUIRED)

# 輸出 OpenCV 函式庫的詳細資訊作為狀態訊息。
message(STATUS "OpenCV library: ${OpenCV_INSTALL_PATH}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# 如果需要進行除錯，取消下面這行的註解，讓建置過程在此處失敗。
# message(FATAL_ERROR "DEBUG...")

# 設定 ncnn 函式庫的路徑，這是為 WebAssembly 建置的版本
set(ncnn_DIR "~/Project/Lib/ncnn-20240410-webassembly/${WASM_FEATURE}/lib/cmake/ncnn")
find_package(ncnn REQUIRED)

# # 設定 C 編譯器的旗標，以配置 WebAssembly 特定的設定。
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s FORCE_FILESYSTEM=1 -s INITIAL_MEMORY=256MB -s EXIT_RUNTIME=1")

# # 設定 C++ 編譯器的旗標，以配置 WebAssembly 特定的設定。
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s FORCE_FILESYSTEM=1 -s INITIAL_MEMORY=256MB -s EXIT_RUNTIME=1")

# # 設定 WebAssembly 建置的鏈結旗標。
# set(CMAKE_EXECUTBLE_LINKER_FLAGS "${CMAKE_EXECUTBLE_LINKER_FLAGS} -s FORCE_FILESYSTEM=1 -s INITIAL_MEMORY=256MB -s EXIT_RUNTIME=1")

# # 新增額外的旗標以匯出特定函式，並將資產預加載到 WebAssembly 檔案系統中
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -sEXPORTED_FUNCTIONS=['_main','_malloc','_free'] --preload-file ${CMAKE_CURRENT_SOURCE_DIR}/assets@.")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -sEXPORTED_FUNCTIONS=['_main','_malloc','_free'] --preload-file ${CMAKE_CURRENT_SOURCE_DIR}/assets@.")
# set(CMAKE_EXECUTBLE_LINKER_FLAGS "${CMAKE_EXECUTBLE_LINKER_FLAGS} -sEXPORTED_FUNCTIONS=['_main','_malloc','_free'] --preload-file ${CMAKE_CURRENT_SOURCE_DIR}/assets@.")

# 增加需要編譯的 C++ 檔案
add_executable(${PROJECT_NAME} main.cpp)

# 指定輸出文件名稱，放置於 "dest" 目錄中，並根據 WASM_FEATURE 命名
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ../dest/${PROJECT_NAME}-${WASM_FEATURE})

# 鏈結 OpenCV 函式庫
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# 鏈結 ncnn 函式庫
target_link_libraries(${PROJECT_NAME} ncnn)
