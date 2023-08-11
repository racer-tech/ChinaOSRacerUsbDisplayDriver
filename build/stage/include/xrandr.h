#ifndef X11_SCREEN_H
#define X11_SCREEN_H
//=========== X window include =============
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XShm.h>
#include <X11/extensions/Xrandr.h>

//#define XDEBUG 

struct shmimage
{
    XShmSegmentInfo shminfo ;
    XImage * ximage ;
    unsigned int * data ; // will point to the image's BGRA packed pixels
} ;
unsigned  char const Cursor_image [16*40]= //160*4
{0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,
    0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0xff,0xff,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,
};
class X11_Screen 
{
public:
    X11_Screen(){
        
    }
    int init_dsp();
    int createimage( Display * dsp, struct shmimage * image, int width, int height );
    void destroyimage( Display * dsp, struct shmimage * image );
    int informationCheck ();
    void cursorPosition();
    struct shmimage screenshot(bool exMode);
    void combineCursorBuffer(struct shmimage * image);

    int root_x, root_y;
    Display * dsp_share;
private:
    bool secMode = false;
    XRRCrtcInfo	 *crtc_primary;
    XRRCrtcInfo  *crtc_extend;
    XRROutputInfo *extend_output;
    int		query = False;
    int		action_requested = False;
    char          *display_name = NULL;
    Bool	setit = False;
    Bool    	setit_1_2 = False;
    Bool    	query_1_2 = False;
    Bool	query_1 = False;
    Bool	current = False;
    
};


#endif

//==================================
