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

# 增加需要編譯的 C++ 檔案
add_executable(${PROJECT_NAME} main.cpp)

# 指定輸出文件名稱，放置於 "dest" 目錄中，並根據 WASM_FEATURE 命名
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ../dest/${PROJECT_NAME}-${WASM_FEATURE})

# 鏈結 OpenCV 函式庫
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# 鏈結 ncnn 函式庫
target_link_libraries(${PROJECT_NAME} ncnn)
