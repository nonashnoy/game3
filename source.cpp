/*
    This source code is protected by copyright.
    © nohashduck <dobutsuduck@gmail.com>
*/

#include "source.hpp"
#include "image.hpp"

auto main(void) -> int {
    ns_window::c_window nswcw_window;
    ns_image::c_image nsici_location("./resources/location.png", 0, 0, 1920, 1080, 0, 0);
    ns_image::c_image nsici_object_1("./resources/tileset.png", 0, 0, 170, 180, 1542, 220);
    ns_image::c_image nsici_object_2("./resources/tileset.png", 170, 0, 124, 186, 1678, 216);
    ns_image::c_image nsici_object_3("./resources/tileset.png", 294, 0, 243, 136, 1051, 261);
    ns_image::c_image nsici_object_4("./resources/tileset.png", 555, 0, 282, 302, 1014, 663);
    ns_image::c_image nsici_object_5("./resources/tileset.png", 294, 136, 94, 64, 1084, 216);
    ns_image::c_image nsici_object_6("./resources/tileset.png", 0, 180, 101, 255, 0, 132);
    ns_image::c_image nsici_object_7("./resources/tileset.png", 170, 186, 108, 157, 10, 334);
    ns_image::c_image nsici_object_8("./resources/tileset.png", 278, 200, 277, 121, 121, 836);
    ns_image::c_image nsici_object_9("./resources/tileset.png", 101, 340, 114, 170, 20, 839);
    ns_image::c_image nsici_object_10("./resources/tileset.png", 239, 343, 89, 177, 404, 775);

    ns_image::c_image nsici_door_1("./resources/tileset.png", 837, 0, 148, 234, 1355, 128);
    ns_image::c_image nsici_door_2("./resources/tileset.png", 985, 0, 45, 310, 988, 142);
    ns_image::c_image nsici_door_3("./resources/tileset.png", 1030, 0, 43, 331, 895, 136);
    ns_image::c_image nsici_door_4("./resources/tileset.png", 1073, 0, 141, 243, 439, 130);
    ns_image::c_image nsici_door_5("./resources/tileset.png", 1214, 0, 90, 338, 545, 708);
    ns_image::c_image nsici_door_6("./resources/tileset.png", 1304, 0, 143, 238, 854, 687);
    ns_image::c_image nsici_door_7("./resources/tileset.png", 1447, 0, 150, 246, 1354, 676);
    ns_image::c_image nsici_door_8("./resources/tileset.png", 1597, 0, 84, 357, 1826, 673);
    ns_image::c_image nsici_door_9("./resources/tileset.png", 1681, 0, 62, 340, 691, 696);

    ns_image::c_image nsici_player("./resources/humans.png", 0, 0, 103, 213, 1687, 823);

    bool b_player_move = false, b_enter_room = false;
    int i_player_x = 1687, i_player_y = 823, i_room = 0;
    int i_player_move_x = 1687, i_player_move_y = 823, i_move_room = 0;

    while (nswcw_window.b_is_open() == true) {
        SDL_Delay(1);
        if (b_player_move == true) {
            if (i_player_x < i_player_move_x) {
                i_player_x = i_player_x + 1;
            } else if (i_player_x > i_player_move_x) {
                i_player_x = i_player_x - 1;
            } else if (i_player_x == i_player_move_x) {
                b_player_move = false;
            }

            nsici_player.v_set_position_x(i_player_x);
        } else if (b_enter_room == true) {


            nsici_player.v_set_position_y(i_player_y);
        } else if (nswcw_window.b_is_event(nsici_location, 0) == true && b_player_move == false) {
            if (i_room == 0) {
                if (nswcw_window.b_is_event(nsici_door_7, 0) == true) {
                    b_enter_room = true;
                    i_move_room = 1;
                    i_player_move_x = 1369;
                } else if (nswcw_window.i_mouse_x < 777) {
                    i_player_move_x = 777;
                } else if (nswcw_window.i_mouse_x > 1774) {
                    i_player_move_x = 1774;
                } else {
                    i_player_move_x = nswcw_window.i_mouse_x;
                }
            } else if (i_room == 1) {
                if (nswcw_window.b_is_event(nsici_door_1, 0) == true) {
                    b_enter_room = true;
                    i_move_room = 0;
                    i_player_move_x = 1377;
                } else if (nswcw_window.i_mouse_x < 1062) {
                    i_player_move_x = 1062;
                } else if (nswcw_window.i_mouse_x > 1733) {
                    i_player_move_x = 1733;
                } else {
                    i_player_move_x = nswcw_window.i_mouse_x;
                }
            }

            b_player_move = true;
        }

        nswcw_window.v_clear();

        nswcw_window.v_draw(nsici_door_1);
        nswcw_window.v_draw(nsici_door_2);
        nswcw_window.v_draw(nsici_door_3);
        nswcw_window.v_draw(nsici_door_4);
        nswcw_window.v_draw(nsici_door_5);
        nswcw_window.v_draw(nsici_door_6);
        nswcw_window.v_draw(nsici_door_7);
        nswcw_window.v_draw(nsici_door_8);
        nswcw_window.v_draw(nsici_door_9);

        nswcw_window.v_draw(nsici_location);
        nswcw_window.v_draw(nsici_object_1);
        nswcw_window.v_draw(nsici_object_2);
        nswcw_window.v_draw(nsici_object_3);
        nswcw_window.v_draw(nsici_object_4);
        nswcw_window.v_draw(nsici_object_5);
        nswcw_window.v_draw(nsici_object_6);
        nswcw_window.v_draw(nsici_object_7);
        nswcw_window.v_draw(nsici_object_8);
        nswcw_window.v_draw(nsici_object_9);
        nswcw_window.v_draw(nsici_object_10);

        nswcw_window.v_draw(nsici_player);

        nswcw_window.v_display();
    }

    return 0;
}