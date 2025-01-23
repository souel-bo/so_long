#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;




int exit_window(int button, void *data_ptr)
{
    t_vars *data = data_ptr;

    if (button == ESC_KEY)
    {
        printf("esc pressed");
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return 0; 
}

int main()
{
    t_vars data;
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.win = mlx_new_window(data.mlx, 800, 800, "test");
    if (!data.win)
        return (1);
    mlx_key_hook(data.win, exit_window, &data);
    mlx_loop(data.mlx);
}