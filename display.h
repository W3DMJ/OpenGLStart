//
// Created by w3dmj on 8/21/21.
//

#ifndef INC_02_OPENGLSTART_DISPLAY_H
#define INC_02_OPENGLSTART_DISPLAY_H

#include <string>
#include <SDL2/SDL.h>

#define DEFAULT_DISPLAY_WIDTH  768
#define DEFAULT_DISPLAY_HEIGHT 768
#define DEFAULT_DISPLAY_TITLE  "OPENGL START"

class Display {
public:
    Display(int displayWidth, int displayHeight, const std::string& displayTitle);
    Display();
    virtual ~Display();

    void clear(float r = 0.0f, float g = 0.15f, float b = 0.3f, float a = 1.0f);
    void Update();
    bool IsClosed() {return mIsClosed;};

    int GetHeight() { return mHeight;};
    int GetWidth() { return mWidth;};

private:
    SDL_Window* mWindow;
    SDL_GLContext mGLContext;
    bool mIsClosed;

    int mWidth;
    int mHeight;

};


#endif //INC_02_OPENGLSTART_DISPLAY_H
