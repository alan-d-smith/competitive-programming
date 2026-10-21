TARGET = cf_1A
FLAGS = -std=c++20 -Wall -Wconversion -Wfatal-errors -g -fsanitize=undefined,address

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	g++ $(FLAGS) $(TARGET).cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	@for f in in/$(TARGET)*.in; do \
		echo "== $$f expected:"; cat $${f%.in}.ans; \
		echo "-- got:"; ./$(TARGET) < $$f | tee out; echo; \
		diff -b out $${f%.in}.ans > /dev/null && echo "-- ok" || echo "-- WRONG"; \
	done