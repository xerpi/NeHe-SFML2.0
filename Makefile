CXXFLAGS = -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions  -O2
LDFLAGS = -lGL -lGLU -pthread -static-libgcc -static-libstdc++ -lsfml-graphics -lsfml-window -lsfml-system -Wl,--gc-sections

all: nehe_lesson1 nehe_lesson2 nehe_lesson3 nehe_lesson4 nehe_lesson5 \
     nehe_lesson6 nehe_lesson7 nehe_lesson8 nehe_lesson9 nehe_lesson10 \
     nehe_lesson11 nehe_lesson12 sfml_compile_test sfml_window_events \
     sfml_window_open sfml_window_opengl sfml_window_time

clean:
	rm -f obj/*
	rm -f bin/*

nehe_lesson1: nehe_lesson1.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

nehe_lesson2: nehe_lesson2.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

nehe_lesson3: nehe_lesson3.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

nehe_lesson4: nehe_lesson4.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

nehe_lesson5: nehe_lesson5.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

nehe_lesson6: nehe_lesson6.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

nehe_lesson7: nehe_lesson7.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

nehe_lesson8: nehe_lesson8.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

nehe_lesson9: nehe_lesson9.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

nehe_lesson10: nehe_lesson10.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

nehe_lesson11: nehe_lesson11.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  
	
nehe_lesson12: nehe_lesson12.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

sfml_compile_test: sfml_compile_test.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

sfml_window_events: sfml_window_events.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

sfml_window_open: sfml_window_open.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

sfml_window_opengl: sfml_window_opengl.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  

sfml_window_time: sfml_window_time.cpp
	g++ $(CXXFLAGS)  -c $^ -o obj/$(addsuffix .o, $(basename $^))
	g++  -o bin/$@ obj/$(addsuffix .o, $(basename $^)) $(LDFLAGS) -s  
