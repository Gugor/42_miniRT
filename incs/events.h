
#ifndef EVENTS_H
# define EVENTS_H

# include "scene.h"

/* KEY CODES */
# define KEY_ESCAPE 65307
# define KEY_0   48
# define KEY_1   49
# define KEY_2   50
# define KEY_UP   65362
# define KEY_DOWN   65364
# define KEY_LEFT   65361
# define KEY_RIGHT   65363
# define KEY_ROT_UP   119
# define KEY_ROT_DOWN   115
# define KEY_ROT_LEFT   97
# define KEY_ROT_RIGHT   100
# define KEY_FOV_UP   101
# define KEY_FOV_DOWN   113

/* Events */
# define SHADES_MODE (1 << 0)
# define CAMERA_MODE (1 << 1)
# define CAMERA_DEPTH (1 << 2)
# define STOP_INPUT_LAYER (1 << 30)


enum EventHandlerType
{
    ON_KEYDOWN = 2,
    ON_KEYUP = 3,
    ON_MOUSEDOWN = 4,
    ON_MOUSEUP = 5,
    ON_MOUSEMOVE = 6,
    ON_EXPOSE = 12,
    ON_DESTROY = 17
};

enum XEvent
{
    KeyPress = 2,
    KeyRelease = 3,
    ButtonPress = 4,
    ButtonRelease = 5,
    MotionNotify = 6,
    EnterNotify = 7,
    LeaveNotify = 8,
    FocusIn = 9,
    FocusOut = 10,
    KeymapNotify = 11,
    Expose = 12,
    GraphicsExpose = 13,
    NoExpose = 14,
    VisibilityNotify = 15,
    CreateNotify = 16,
    DestroyNotify = 17,
    UnmapNotify = 18,
    MapNotify = 19,
    MapRequest = 20,
    ReparentNotify = 21,
    ConfigureNotify = 22,
    ConfigureRequest = 23,
    GravityNotify = 24,
    ResizeRequest = 25,
    CirculateNotify = 26,
    CirculateRequest = 27,
    PropertyNotify = 28,
    SelectionClear = 29,
    SelectionRequest = 30,
    SelectionNotify = 31,
    ColormapNotify = 32,
    ClientMessage = 33,
    MappingNotify = 34,
    GenericEvent = 35,
    LASTEvent = 36 
}; 

enum XEventMask
{
    NoEventMask = 0L,
    KeyPressMask = 1L << 0,
    KeyReleaseMask = 1L << 1,
    ButtonPressMask = 1L << 2,
    ButtonReleaseMask = 1L << 3,
    EnterWindowMask = 1L << 4,
    LeaveWindowMask = 1L << 5,
    PointerMotionMask = 1L << 6,
    PointerMotionHintMask = 1L << 7,
    Button1MotionMask = 1L << 8,
    Button2MotionMask = 1L << 9,
    Button3MotionMask = 1L << 10,
    Button4MotionMask = 1L << 11,
    Button5MotionMask = 1L << 12,
    ButtonMotionMask = 1L << 13,
    KeymapStateMask = 1L << 14,
    ExposureMask = 1L << 15,
    VisibilityChangeMask = 1L << 16,
    StructureNotifyMask = 1L << 17,
    ResizeRedirectMask = 1L << 18,
    SubstructureNotifyMask = 1L << 19,
    SubstructureRedirectMask = 1L << 20,
    FocusChangeMask = 1L << 21,
    PropertyChangeMask = 1L << 22,
    ColormapChangeMask = 1L << 23,
    OwnerGrabButtonMask = 1L << 24
};

enum e_config_mode
{
    ACTIVE_FLG = 0,
    UNACTIVE_FLG = 1,
    TOGGLE_FLG = 2,
};

void	listen_events(void);

void	init_events(t_scene *scn);


int		toggle_camera_movement(int keycode);
int		move_camera(int keycode);
int		zoom_camera(int keycode);
int		path_tracing_depth(int keycode);
void	cam_displace_horizontal(t_camera *cam, int dir, double amount);
void	cam_displace_vertical(t_camera *cam, int dir, double amount);
int		path_tracing_depth(int keycode);

void	set_input_event(int mask, int condition);
bool	check_flags(int flags);
bool	input_is_active(int flag);


#endif