#include "splashkit.h"

int change_logo_color(int current_color)
{   
    int new_color;
    do {
        new_color = rnd(12) + 1;
    }
    while (new_color == current_color);
    return new_color;
}

int main()
{
    open_window("DVD Screensaver", 800, 600);

    double xpos;
    double ypos;
    double boundary_d;
    double boundary_u;
    double boundary_r;
    double boundary_l;
    int logo_color;
    int direction;

    xpos = 300;
    ypos = 300;
    boundary_d = screen_height() - 50;
    boundary_u = -10;
    boundary_r = screen_width() - 100;
    boundary_l = -10;
    logo_color = rnd(12) + 1;
    direction =  1;
    // 1 = South East
    // 2 = North East
    // 3 = North West
    // 4 = South West

    do
    {
        process_events();

        switch(direction)
        {
            case 1: // South-East
                xpos = xpos + 3;
                ypos = ypos + 3;
                if ( xpos > boundary_r )
                {
                    direction = 4;
                    logo_color = change_logo_color(logo_color);
                    
                }
                if ( ypos > boundary_d )
                {
                    direction = 2;
                    logo_color = change_logo_color(logo_color);
                }
                break;
            case 2: // North-East
                xpos = xpos + 3;
                ypos = ypos - 3;
                if ( ypos < boundary_u )
                {
                    direction = 1;
                    logo_color = change_logo_color(logo_color);
                }
                if ( xpos > boundary_r )
                {
                    direction = 3;
                    logo_color = change_logo_color(logo_color);
                }
                break;
            case 3: // North-West      
                xpos = xpos - 3;
                ypos = ypos - 3;
                if ( xpos < boundary_l )
                {
                    direction = 2;
                    logo_color = change_logo_color(logo_color);
                }
                if ( ypos < boundary_u )
                {
                    direction = 4;
                    logo_color = change_logo_color(logo_color);
                }
                break;
            case 4: // South-West
                xpos = xpos - 3;
                ypos = ypos + 3;
                if ( ypos > boundary_d )
                {
                    direction = 3;
                    logo_color = change_logo_color(logo_color);
                }
                if ( xpos < boundary_l )
                {
                    direction = 1;
                    logo_color = change_logo_color(logo_color);
                }            
                break;
        }

        clear_screen(COLOR_BLACK);

        switch(logo_color)
        {
            case 1:
                load_bitmap("logo_red", "logo_red.png");
                draw_bitmap("logo_red", xpos, ypos);
            break;
            case 2:
                load_bitmap("logo_blue", "logo_blue.png");
                draw_bitmap("logo_blue", xpos, ypos);
            break;
            case 3:
                load_bitmap("logo_yellow", "logo_yellow.png");
                draw_bitmap("logo_yellow", xpos, ypos);
            break;
            case 4:
                load_bitmap("logo_green", "logo_green.png");
                draw_bitmap("logo_green", xpos, ypos);
            break;
            case 5:
                load_bitmap("logo_lime_green", "logo_lime_green.png");
                draw_bitmap("logo_lime_green", xpos, ypos);
            break;    
            case 6:
                load_bitmap("logo_brown", "logo_brown.png");
                draw_bitmap("logo_brown", xpos, ypos);
            break;    
            case 7:
                load_bitmap("logo_grey", "logo_grey.png");
                draw_bitmap("logo_grey", xpos, ypos);
            break;    
            case 8:
                load_bitmap("logo_light_blue", "logo_light_blue.png");
                draw_bitmap("logo_light_blue", xpos, ypos);
            break;    
            case 9:
                load_bitmap("logo_white", "logo_white.png");
                draw_bitmap("logo_white", xpos, ypos);
            break;                                         
            case 10:
                load_bitmap("logo_orange", "logo_orange.png");
                draw_bitmap("logo_orange", xpos, ypos);
            break;                                         
            case 11:
                load_bitmap("logo_pink", "logo_pink.png");
                draw_bitmap("logo_pink", xpos, ypos);
            break;                                         
            case 12:
                load_bitmap("logo_purple", "logo_purple.png");
                draw_bitmap("logo_purple", xpos, ypos);
            break;                                                                        
        }
        refresh_screen(60);
    }
    while ( not quit_requested() );

    return 0;
}