run:
	@echo "running test"
	@g++ test.cpp
	@./a.out
	@rm a.out

comp:
	@echo "compling test"
	@g++ test.cpp

clean:
	@echo "cleaning"
	@rm a.out

