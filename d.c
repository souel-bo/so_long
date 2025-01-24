#include "so_long.h"

int main()
{
    void *mlx;
    void *win;
    void *img;
    int img_width, img_height;

    // Initialize MiniLibX
    mlx = mlx_init();
    if (!mlx)
    {
        fprintf(stderr, "Error initializing MiniLibX\n");
        return 1;
    }

    // Create a new window
    win = mlx_new_window(mlx, 800, 600, "Display Image");
    if (!win)
    {
        fprintf(stderr, "Error creating window\n");
        return 1;
    }

    // Load the XPM image
    img = mlx_xpm_file_to_image(mlx, "test.xpm", &img_width, &img_height);
    if (!img)
    {
        fprintf(stderr, "Error loading image\n");
        return 1;
    }

    // Display the image in the window at coordinates (0, 0)
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // Set up an event loop to keep the window open
    mlx_loop(mlx);

    return 0;
}