tictactoe: tictactoe.o logic.o
	@gcc tictactoe.o logic.o -o tictactoe
	@echo "Building..."
tictactoe.o: tictactoe.c logic.h
	@gcc -c tictactoe.c

logic.o: logic.c logic.h
	@gcc -c logic.c

clean:
	@echo "Cleaning object files..."
	@rm *.o
