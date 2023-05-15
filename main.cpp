#include "denoiser/denoiser.hpp"
#include "cxxopts/cxxopts.hpp"


int main(int argc, char *argv[]) {
    cxxopts::Options options("TV mesh denoiser", "Mesh denoising via TV regularization on normals");
    options.add_options()
            ("obj", "obj file containing the input mesh", cxxopts::value<std::string>())
            ;
    options.parse_positional({"obj"});
    auto args = options.parse(argc, argv);


    tvd::hello(args["obj"].as<std::string>());
}