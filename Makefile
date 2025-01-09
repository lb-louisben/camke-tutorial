# 定义变量
BUILD_DIR := build

# 默认目标
.PHONY: all
all: configure build

# 配置 CMake
.PHONY: configure
configure:
	@echo "Configuring project..."
	@if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
	@cd $(BUILD_DIR) && cmake ..

# 构建项目
.PHONY: build
build:
	@echo "Building project..."
	@cd $(BUILD_DIR) && make

# 清理构建目录
.PHONY: clean
clean:
	@echo "Cleaning build directory..."
	@rm -rf $(BUILD_DIR)

# 一键清理并重构建
.PHONY: rebuild
rebuild: clean all

# 运行测试
.PHONY: test
test:
	@echo "Running tests..."
	@cd $(BUILD_DIR) && ctest --verbose

# Git 操作
.PHONY: git-status git-add git-commit git-push
git-status:
	@git status

git-add:
	@git add .

# Git 提交
git-commit:
	@if [ "$(strip $@)" = "" ]; then \
		echo "Usage: make git-commit MESSAGE=\"Your commit message\""; \
		exit 1; \
	fi; \
	git commit -m "$@"

git-push:
	@git push origin $(BRANCH)
