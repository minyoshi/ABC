.PHONY: help clean test

help: ## ヘルプを表示
	@printf "\033[1;34m使い方:\033[0m\n"
	@printf "  make <ターゲット>\n\n"
	@printf "\033[1;34mターゲット:\033[0m\n"
	@awk 'BEGIN {FS = ":.*##"} /^[a-zA-Z0-9_-]+:.*##/ { printf "  \033[1;32m%-15s\033[0m %s\n", $$1, $$2 }' $(MAKEFILE_LIST)

clean: ## プロジェクト配下の .out / .dSYM を削除
	@find . -type f -name '*.out' -delete
	@find . -type d -name '*.dSYM' -prune -exec rm -rf {} \;

test: ##テスト実施
	@./test/test.sh