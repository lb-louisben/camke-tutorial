# 定义目标目录
BUILD_DIR = build
DEBUG_DIR = $(BUILD_DIR)/Debug
RELEASE_DIR = $(BUILD_DIR)/Release

# 默认构建类型
BUILD_TYPE ?= Debug

# 可执行文件名
EXECUTABLE = main

.PHONY: all debug release clean run

# 默认目标
all: $(BUILD_TYPE)

# Debug 构建
debug:
	mkdir -p $(DEBUG_DIR)
	cd $(DEBUG_DIR) && cmake -DCMAKE_BUILD_TYPE=Debug ../..
	make -C $(DEBUG_DIR)
	@echo "\033[1;32m> You can run ./$(DEBUG_DIR)/$(EXECUTABLE) to run this system\033[0m"

# Release 构建
release:
	mkdir -p $(RELEASE_DIR)
	cd $(RELEASE_DIR) && cmake -DCMAKE_BUILD_TYPE=Release ../..
	make -C $(RELEASE_DIR)
	@echo "\033[1;32m> You can run ./$(RELEASE_DIR)/$(EXECUTABLE) to run this system\033[0m"

# 运行目标
run:
	@echo "\033[1;34mRunning $(BUILD_TYPE) build...\033[0m"
	./$(BUILD_DIR)/$(BUILD_TYPE)/$(EXECUTABLE)

# 清理构建
clean:
	rm -rf $(BUILD_DIR)
	@echo "\033[1;31m> All build files have been cleaned.\033[0m"
