name = libsay.a
srcs = my_str.c
test = test/test_libsay_functions.c test/unity.c
cflg = -Wall -Wextra -Werror
build = ./build/
objs = ${foreach obj, ${srcs:.c=.o}, ${build}${obj}}
tobjs = ${foreach obj, ${test:.c=.o}, ${build}${obj}}

all:			${name}
${name}:		${objs}
	ar rcs ${name} ${objs}
	ranlib ${name}

${build}%.o:	%.c
	mkdir -p ${@D}
	cc -c ${cflg} $< -o $@

test:	${name} ${tobjs}
	cc ${cflg} ${tobjs} -o test_libsay -L. -lsay

${build}test/%.o:	./test/%.c
	mkdir -p ${@D}
	cc -c -I. ${cflg} $< -o $@

clean:
	rm -rf ${build}

fclean:	clean
	rm -rf ${name} test_libsay

re:	fclean all

.PHONY: all clean fclean re