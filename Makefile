name = libsay.a
srcs = my_str.c
cflg = -Wall -Wextra -Werror
build = ./build/
objs = ${foreach obj, ${srcs:.c=.o}, ${build}${obj}}

leak_test_srcs = test/valgrind_test_program.c
test_srcs = test/test_libsay_functions.c test/unity.c
test_objs = ${foreach obj, ${test_srcs:.c=.o}, ${build}${obj}}
leak_test_objs = ${foreach obj, ${leak_test_srcs:.c=.o}, ${build}${obj}}

#	normal build
all:			${name}
${name}:		${objs}
	ar rcs ${name} ${objs}
	ranlib ${name}

${build}%.o:	%.c
	mkdir -p ${@D}
	cc -c ${cflg} $< -o $@
clean:
	rm -rf ${build}

fclean:	clean
	rm -rf ${name} test_libsay leak_test

re:	fclean all


#	tests
test_leak:	${name} ${leak_test_objs}
	cc ${cflg} ${leak_test_objs} -o leak_test -L. -lsay
test:	${name} ${test_objs}
	cc ${cflg} ${test_objs} -o test_libsay -L. -lsay

${build}test/%.o:	./test/%.c
	mkdir -p ${@D}
	cc -c -I. ${cflg} $< -o $@


.PHONY: all clean fclean re test test_leak