src=$(wildcard *.c)
obj=$(patsubst %.c, %.o, $(src))
target=calc
$(target):$(obj)
        gcc $(obj)  -o $(target)
%.o:%.c
        gcc $< -c
.PHONY:clean
clean:
        -rm $(obj) $(target) 
        echo "hello, 我是测试字符串"



#练习
# 目录结构
# .
# ├── include
# │   └── head.h	==> 头文件, 声明了加减乘除四个函数
# ├── main.c		==> 测试程序, 调用了head.h中的函数
# └── src
#     ├── add.c	==> 加法运算
#     ├── div.c	==> 除法运算
#     ├── mult.c  ==> 乘法运算
#     └── sub.c   ==> 减法运算

target = app
src=$(wildcard *.c ./src/*.c)
obj=$(patsubst %.c,%.o,$(src))
include=./include
$(target):$(obj)
	gcc $^ -o $@

%.o:%.c 
	gcc $< -c -I $(include) -o $@

.PHONY:clean
clean:
	-rm $(obj) $(taregt) -f