#include <Kokkos_Core.hpp>
#include <paraconf.h>
#include <pdi.h>

int main(int argc, char** argv)
{
    Kokkos::ScopeGuard scope(argc, argv);
    PC_tree_t conf = PC_parse_string("");
    PDI_init(conf);
    PDI_finalize();
    PC_tree_destroy(&conf);
    return 0;
}
