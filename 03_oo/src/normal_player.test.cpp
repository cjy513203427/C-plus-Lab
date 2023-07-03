#include <catch2/catch_test_macros.hpp>
#include "util.test.hpp"

#include "normal_player.hpp"

TEST_CASE("normal player") {
    SECTION("circle") {
        NormalPlayer player(Color::CIRCLE);
        test_single_move(player, Field::CIRCLE);
    }
    SECTION("cross") {
        NormalPlayer player(Color::CROSS);
        test_single_move(player, Field::CROSS);
    }
}
