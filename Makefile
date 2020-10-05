objects = $(patsubst src/%.cpp,%,$(wildcard src/*.cpp))
libs = $(patsubst %.cpp,%,$(wildcard lib/*.cpp))

output_path := ./build

$(addprefix $(output_path)/,$(objects)): $(output_path)/%: $(libs:%=%.cpp) $(libs:%=%.hpp) src/%.cpp
	mkdir -p "$(@D)"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o "$@" "src/$*.cpp" $(libs:%=%.cpp)

$(addprefix run/,$(objects)): run/%: $(output_path)/%
	"$(output_path)/$*"


clean:
	rm -fr "$(output_path)"
