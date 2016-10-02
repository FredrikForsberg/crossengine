CPP     = src/pngtest.cpp
OUTBIN  = bin/pngtest/pngtest
OUTHTML = bin/pngtest/index.html

$(OUTBIN) : $(CPP) bin/pngtest
	g++ $(CPP) -w -lSDL2 -lSDL2_image -o $(OUT)

$(OUTHTML) : $(CPP) bin/pngtest
	emcc $(CPP) -O2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file res/pngtest -o $(OUTHTML)

bin/pngtest :
	mkdir -p bin/pngtest

