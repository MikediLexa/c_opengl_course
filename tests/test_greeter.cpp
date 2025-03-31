#include <catch2/catch_test_macros.hpp>
#include "Greeter.hpp"

TEST_CASE("Greeter funktioniert", "[Greeter]") {
    Greeter g("Tester");
    REQUIRE_NOTHROW(g.greet());
}
