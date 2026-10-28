#include <iostream>
#include <vector>

#include "MilStatus_v0.hpp"

int main() {
    MilStatus cadet(5, "Luna", {"radio", "map"});

    std::cout << "v0: one object is already enough to start the story.\n";
    cadet.printSummary(std::cout);
    std::cout << "At this point we only know the class exists and objects "
                 "can be created.\n";
    return 0;
}
