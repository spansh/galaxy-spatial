.SUFFIXES:
MAKEFLAGS += -r
SHELL := /bin/bash
.DELETE_ON_ERROR:
.PHONY: all test clean


all: GalaxySpatial

%: %.cpp
	g++ -std=c++17 -O0 -g3 -ggdb -fno-eliminate-unused-debug-types -Wall -Wextra -pedantic -Irapidjson/include/ -o $@ $^ -lz -lstdc++fs -L/usr/local/lib -L/usr/lib/x86_64-linux-gnu/  -l:libboost_iostreams.a -lbz2

clean: GalaxySpatial
	rm -rf $^

production:
	g++ -std=c++17 -O3 -msseregparm -flto -msse -msse2 -msse3 -msse4.2 -minline-all-stringops -mfpmath=sse -march=native -Wall -Wextra -pedantic -Irapidjson/include/ -o GalaxySpatial  GalaxySpatial.cpp -lz -lstdc++fs -L/usr/local/lib -L/usr/lib/x86_64-linux-gnu  -l:libboost_iostreams.a -lbz2

gperf:
	gperf -t galaxy.gperf --output-file=GalaxyHash.hpp
	gperf -t body_types.gperf --output-file=BodyTypesHash.hpp
	gperf -t body_subtypes.gperf --output-file=BodySubtypesHash.hpp
