CXX = g++
CXXFLAGS = -O3 -std=c++17 -fPIC
INCLUDES = -I./include -I./extern/pybind11/include
LDFLAGS = -shared

build_ext:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o gauss_jordan_ext.so src/gauss_jordan.cpp python/bindings.cpp $(LDFLAGS) -lpython3.10

clean:
	rm -f gauss_jordan_ext.so

.PHONY: build_ext clean