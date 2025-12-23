hello:
	@echo ' _______________________________________________ '
	@echo '/ To build the program natively                 |' 
	@echo '| make build                                    |'
	@echo '| To build for arm linux                        |'
	@echo '| make build-arm                                |'
	@echo '| A little test                                 |'
	@echo '| make build-test                               |'
	@echo '| And of course there is always                 |'
	@echo '| make clean                                    |'
	@echo ' ----------------------------------------------- '
	@echo '        \   ^__^                                 '
	@echo '         \  (oo)\_______                        '
	@echo '            (__)\       )\/\                  '
	@echo '                ||----w | '
	@echo '                ||     || '

build native-bin: main.c game.c game.h 

	gcc -c main.c game.c
	gcc    main.o game.o -l SDL -o native-bin

build-arm arm-bin: main.c game.c game.h 

	arm-linux-gnuabi-gcc-11 -c main.c game.c
	arm-linux-gnuabi-gcc-11 -static main.o game.o -l SDL -o arm-bin

build-test test-bin: test.c game.c game.h

	gcc -c test.c game.c
	gcc    test.o game.o -l SDL -o test-bin

clean:
	rm -rf *.o *bin
