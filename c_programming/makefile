# ============================================================
# C 语言练习 Makefile
# 编译器：MSVC cl (Microsoft Visual C++ 编译器)
# 用法：在 Visual Studio 开发者命令提示符 (Developer PowerShell) 下运行 make
# ============================================================

# 默认目标：编译 pun.c 生成 pun.exe
# cl 直接一步完成编译+链接，无需手动生成 .o 中间文件
pun: pun.c
	cl pun.c /Fe:pun.exe /nologo

# 清理生成物（MSVC 会额外产生 .obj 文件，一并清理）
clean:
	del pun.exe pun.obj 2>nul

# ============================================================
# 旧版 gcc 规则（已注释，保留备用）
# ============================================================
# a:pun.o
# 	gcc -o a.exe pun.o
# pun.o:pun.c
# 	gcc -c pun.c
# clean:
# 	del a.exe pun.o