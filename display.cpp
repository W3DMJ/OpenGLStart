//
// Created by w3dmj on 8/21/21.
//

#include "display.h"
#include <GL/glew.h>
#include <iostream>

Display::Display(int displayWidth, int displayHeight, const std::string& displayTitle)
{
    mIsClosed = false;
    mWidth = displayWidth;
    mHeight = displayHeight;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    mWindow = SDL_CreateWindow(displayTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayWidth, displayHeight, SDL_WINDOW_OPENGL);
    mGLContext = SDL_GL_CreateContext(mWindow);

    GLenum status = glewInit();
    if (status != GLEW_OK)
        std::cerr << "Glew failed to initialize" << std::endl;

    glOrtho(-(displayWidth/2.0), (displayWidth/2.0), -(displayHeight/2.0), (displayHeight/2.0), 0.0f, 1.0f);
}

Display::Display()
{
    mIsClosed = false;
    mWidth = DEFAULT_DISPLAY_WIDTH;
    mHeight = DEFAULT_DISPLAY_HEIGHT;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    mWindow = SDL_CreateWindow(DEFAULT_DISPLAY_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_DISPLAY_WIDTH, DEFAULT_DISPLAY_HEIGHT, SDL_WINDOW_OPENGL);
    mGLContext = SDL_GL_CreateContext(mWindow);

    GLenum status = glewInit();
    if (status != GLEW_OK)
        std::cerr << "Glew failed to initialize" << std::endl;

    glOrtho(-(DEFAULT_DISPLAY_WIDTH/2.0), (DEFAULT_DISPLAY_WIDTH/2.0), -(DEFAULT_DISPLAY_HEIGHT/2.0), (DEFAULT_DISPLAY_HEIGHT/2.0), 0.0f, 1.0f);
}

Display::~Display()
{
    SDL_GL_DeleteContext(mGLContext);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Display::clear(float r /*= 0.0f*/, float g /*= 0.15f*/, float b /*= 0.3f*/, float a /*= 1.0f*/)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);

}

void Display::Update()
{
    SDL_GL_SwapWindow(mWindow);
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            mIsClosed = true;
    }
}