objects = $(patsubst src/%.cpp,%,$(wildcard src/*.cpp))

output_path := ./build

$(addprefix $(output_path)/,$(objects)): $(output_path)/%: src/%.cpp
	mkdir -p "$(@D)"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o "$@" "src/$*.cpp"

$(addprefix run/,$(objects)): run/%: $(output_path)/%
	"$(output_path)/$*"


clean:
	rm -fr "$(output_path)"