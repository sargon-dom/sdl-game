CXX ?= clang++
MKDIR := mkdir -p
CXXFLAGS += `pkg-config --cflags sdl2 SDL2_image`
CXXFLAGS += -Wall -Werror -Wextra -Weffc++ -pedantic -std=c++0x -DDEBUG
LDFLAGS += `pkg-config --libs sdl2 SDL2_image`
PROGS := bin/game
OBJS := $(patsubst src/%.cpp,obj/%.o, $(wildcard src/*.cpp))

.PHONY: all clean

all: build

build: $(PROGS)

clean:
	rm -rf $(PROGS) $(OBJS)

run: $(PROGS)
	./$(PROGS)

bin/game: obj/main.o \
	obj/game.o \
	obj/graphics.o

$(PROGS):
	@$(MKDIR) $(dir $@)
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $@

obj/%.o : src/%.cpp
	@$(MKDIR) $(dir $@)
	$(CXX) $< $(CXXFLAGS) -c -MD -o $@

