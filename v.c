#include "minilibx-linux/mlx.h"
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Function to handle key press events
int handle_key_press(int keycode, void *param)
{
    (void)param; // Avoid unused parameter warning
    printf("Key pressed: %d\n", keycode);
    return 0;
}

int main()
{
    void *mlx;
    void *win;

    // Initialize MiniLibX
    mlx = mlx_init();
    if (!mlx)
    {
        fprintf(stderr, "Error initializing MiniLibX\n");
        return 1;
    }

    // Create a new window
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Keycode Finder");
    if (!win)
    {
        fprintf(stderr, "Error creating window\n");
        return 1;
    }

    // Set up the key press handler
    mlx_key_hook(win, handle_key_press, NULL);

    // Enter the event loop
    mlx_loop(mlx);

    return 0;
}