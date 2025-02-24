#include <Kokkos_Core.hpp>
#include <paraconf.h>
#include <pdi.h>
#include <string>

int main(int argc, char **argv) {
  std::string const pdi_conf(R"df(
metadata:
    a: int
plugins:
    trace:
)df");
  Kokkos::ScopeGuard const scope(argc, argv);
  PC_tree_t conf = PC_parse_string(pdi_conf.c_str());
  PDI_init(conf);
  int a = 1;
  PDI_expose("expose a", &a, PDI_INOUT);
  PDI_finalize();
  PC_tree_destroy(&conf);
  return 0;
}
