# 举例: 有源文件 a.c b.c c.c head.h, 需要生成可执行程序 app
################# 例1 #################
app:a.c b.c c.c
	gcc a.c b.c c.c -o app

################# 例2 #################
# 有多个目标, 多个依赖, 多个命令
app,app1:a.c b.c c.c d.c
	gcc a.c b.c -o app
	gcc c.c d.c -o app1
	
################# 例3 #################	
# 规则之间的嵌套
app:a.o b.o c.o
	gcc a.o b.o c.o -o app
# a.o 是第一条规则中的依赖
a.o:a.c
	gcc -c a.c
# b.o 是第一条规则中的依赖
b.o:b.c
	gcc -c b.c
# c.o 是第一条规则中的依赖
c.o:c.c
	gcc -c c.c
# 这是一个规则，里边使用了自定义变量

obj= add.o div.o main.o mult.o sub.o
target=calc
$(target):$(pbj)
	gcc $(obj) -o $(target)

# AR	生成静态库库文件的程序名称	ar
# AS	汇编编译器的名称	as
# CC	C 语言编译器的名称	cc
# CPP	C 语言预编译器的名称	$(CC) -E
# CXX	C++语言编译器的名称	g++
# FC	FORTRAN 语言编译器的名称	f77
# RM	删除文件程序的名称	rm -f
# ARFLAGS	生成静态库库文件程序的选项	无默认值
# ASFLAGS	汇编语言编译器的编译选项	无默认值
# CFLAGS	C 语言编译器的编译选项	无默认值
# CPPFLAGS	C 语言预编译的编译选项	无默认值
# CXXFLAGS	C++语言编译器的编译选项	无默认值
# FFLAGS	FORTRAN 语言编译器的编译选项	无默认

# 这是一个规则，里边使用了自定义变量和预定义变量
obj=add.o  div.o  main.o  mult.o  sub.o
target=calc
CFLAGS=-O3 # 代码优化
$(target):$(obj)
        $(CC)  $(obj) -o $(target) $(CFLAGS)

# $*	表示目标文件的名称，不包含目标文件的扩展名
# $+	表示所有的依赖文件，这些依赖文件之间以空格分开，按照出现的先后为顺序，其中可能 包含重复的依赖文件
# $<	表示依赖项中第一个依赖文件的名称
# $?	依赖项中，所有比目标文件时间戳晚的依赖文件，依赖文件之间以空格分开
# $@	表示目标文件的名称，包含文件扩展名
# $^	依赖项中，所有不重复的依赖文件，这些文件之间以空格分开

# 这是一个规则，里边使用了自定义变量
# 使用自动变量, 替换相关的内容
calc:add.o  div.o  main.o  mult.o  sub.o
	gcc $^ -o $@ 			# 自动变量只能在规则的命令中使
# 模式匹配 -> 通过一个公式, 代表若干个满足条件的规则
# 依赖有一个, 后缀为.c, 生成的目标是一个 .o 的文件, % 是一个通配符, 匹配的是文件名
%.o:%.c
	gcc $< -c

# 使用举例: 分别搜索三个不同目录下的 .c 格式的源文件
src = $(wildcard /home/robin/a/*.c /home/robin/b/*.c *.c)  # *.c == ./*.c
# 返回值: 得到一个大的字符串, 里边有若干个满足条件的文件名, 文件名之间使用空格间隔
/home/robin/a/a.c /home/robin/a/b.c /home/robin/b/c.c /home/robin/b/d.c e.c f.c


src = a.cpp b.cpp c.cpp e.cpp
# 把变量 src 中的所有文件名的后缀从 .cpp 替换为 .o
obj = $(patsubst %.cpp, %.o, $(src)) 
# obj 的值为: a.o b.o c.o e.o


#具体写法：
##1
clac:add.c div.c main.c mult.c sub.C
		gcc add.c div.c main.c mult.c sub.c -o calc
#这个版本的优点：书写简单

#这版本的缺点：只要依赖中的某一个源文件被修改，所有的源文件都需要被重新编译，太耗时、效率低

#改进方式：提高效率，修改哪一个源文件, 哪个源文件被重新编译, 不修改就不重新编译


##2
calc:add.o  div.o  main.o  mult.o  sub.o
        gcc  add.o  div.o  main.o  mult.o  sub.o -o calc

# 如果修改了add.c, add.o 被重新生成
add.o:add.c
        gcc add.c -c

div.o:div.c
        gcc div.c -c

main.o:main.c
        gcc main.c -c

sub.o:sub.c
        gcc sub.c -c

mult.o:mult.c
        gcc mult.c -c

#这个版本的缺点：规则比较冗余, 需要精简

#改进方式：在 makefile 中使用变量 和 模式匹配


###3
obj=add.o  div.o  main.o  mult.o  sub.o
target=calc

$(target):$(obj)
        gcc $(obj)  -o $(target)

%.o:%.c
        gcc $< -c

##4
src=$(wildcard *.c)
obj=$(patsubst %.c,%.o,$(src))
target=calc
$(target):$(obj)
	gcc $(obj) -o $(target)
%.o:%.c 
	gcc $< -c

#这个版本的缺点：没有文件删除的功能，不能删除项目编译过程中生成的目标文件（*.o）和可执行程序

#改进方式: 在makefile文件中添加新的规则用于删除生成的目标文件（*.o）和可执行程序

clean:
        rm $(obj) $(target)


