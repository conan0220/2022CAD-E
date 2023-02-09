cmake_minimum_required(VERSION 2.9) # 指定最低的 cmake 版本需求
project(2022CAD-E) # 專案名稱

set(CMAKE_BUILD_TYPE "Debug")

include_directories("include") # 指定 include 目錄，告訴 cmake 在這個目錄下找標頭檔

link_directories("lib")

aux_source_directory(src/ SRC_LIST) # 指定原始碼所在目錄，並將檔案名稱存在 SRC_LIST 變數中
add_executable(2022CAD-E ${SRC_LIST}) # 建立一個可執行檔，名稱為 2022CAD-E 並附上原始碼檔案

target_link_libraries(2022CAD-E libsymengine.a)
target_link_libraries(2022CAD-E libgmp.a libgmpxx.a)