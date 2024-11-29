
#include "scene.h"
#include "window.h"
#include "events.h"
#include "memory-handler.h"

int	close(int keycode)
{
	if (keycode == KEY_ESCAPE || keycode == 0)
	{
		clear_scene();
		printf("Window closed...\n");
		exit(0);
	}
	return (0);
}


void listen_events(void)
{
	t_scene *scn;

	scn = get_scene();
	mlx_hook(scn->win->mlx_win, KeyPress , KeyPressMask, close, NULL);
	mlx_hook(scn->win->mlx_win, ON_DESTROY, SubstructureNotifyMask, close, NULL);
}