# 部落格文章範例 
這個範例是使用 Webassembly 整合 NCNN + OpenCV 踩雷的文章的 Sample Code，這裡僅大概的步驟，詳細請參閱部落格。

---
## 環境設定及建置
1. 安裝 Emscripten
2. 安裝 OpenCV
3. 安裝 NCNN
4. 執行底下語法，會產生 Emscripten 在目前 Console 視窗中的環境變數。
   ```
   source ~/Project/Lib/emsdk/emsdk_env.sh
   ```
5. 切換到目前專案的工作目錄。
6. 執行底下命令進行建置，-j6 請根據自己的處理器的數量自行調整。
   ```
   mkdir build && cd build && cmake -DCMAKE_TOOLCHAIN_FILE=$EMSDK/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DWASM_FEATURE=simd .. && make -j6
   ```
7. 若要重新建置請執行底下指令(刪除 build 資料夾，並重新執行上述指令)。
   ```
   cd .. && rm -r build && mkdir build && cd build && cmake -DCMAKE_TOOLCHAIN_FILE=$EMSDK/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DWASM_FEATURE=simd .. && make -j6
   ```

---
## 專案路徑 
```
UserHome
|__ Project
   |__ Lib
   |  |__ emsdk
   |  |__ ncnn-20240410-webassembly
   |  |__ opencv_setup
   |     |__ build_wasm (手動建置)
   |     |__ opencv-4.x
   |__ WebAssemblyDemo
```

---
### 範例網站
Demo 站台 https://lawrence8358.github.io/WebAssemblyDemo/
![範例圖片](wasm-demo.png?raw=true)

---
### 文章連結


---
### License
The MIT license