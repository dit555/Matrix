run:
	@echo "running test"
	@g++ test.cpp Matrix.cpp
	@./a.out
	@rm a.out

comp:
	@echo "compling test"
	@g++ test.cpp Matrix.cpp

clean:
	@echo "cleaning"
	@rm a.out

