gcc3:
	@gcc -Wall 3.c
dgcc3:
	@gcc -Wall -DDEBUG 3.c
indent3:
	@indent --linux-style 3.c

exe3:
	@make gcc3
	./a.out < in3.txt

dexe3:
	@make dgcc3
	./a.out < in3.txt

gcc4:
	@gcc -Wall 4.c
dgcc4:
	@gcc -Wall -DDEBUG 4.c
indent4:
	@indent --linux-style 4.c

exe4:
	@make gcc4
	./a.out < in4.txt

dexe4:
	@make dgcc4
	./a.out < in4.txt
