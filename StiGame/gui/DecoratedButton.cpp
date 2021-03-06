#include "DecoratedButton.h"

namespace StiGame
{
namespace Gui
{

DecoratedButton::DecoratedButton()
    : Item("DecoratedButton"),
      CaptionSupport()
{
    //ctor
    buttonLeft = style->getButtonLeft();
    buttonRight = style->getButtonRight();
    buttonBackground = style->getButtonBackground();

    buttonHighlightLeft = style->getHighlightButtonLeft();
    buttonHighlightRight = style->getHighlightButtonRight();
    buttonHighlightBackground = style->getHighlightButtonBackground();

    surfaceBackground = nullptr;
    surfaceHighlightBackground = nullptr;
}

void DecoratedButton::setForeground(Color* m_foreground)
{
    Item::setForeground(m_foreground);
    stringRenderer.setColor(m_foreground);
}

void DecoratedButton::resized()
{
    drawBackground();
}

void DecoratedButton::onClick(Point *relp)
{
    EventArgs args = EventArgs();
    publish(this, &args);
}

void DecoratedButton::drawBackground()
{
    if(surfaceBackground != nullptr)
    {
        delete surfaceBackground;
        delete surfaceHighlightBackground;
    }

    int min_width = stringRenderer.getWidth() + buttonLeft->getWidth() + buttonRight->getWidth();
    height = buttonBackground->getHeight();

    minimumSize.setDimension(min_width, height);
    maximumSize.setHeight(height);

    if(width < min_width)
    {
        width = min_width;
    }

    surfaceBackground = new Surface(width, height);
    surfaceHighlightBackground = new Surface(width, height);

    SDL_Rect src = SDL_Rect();
    SDL_Rect dst = SDL_Rect();

    src.x = 0;
    src.y = 0;
    src.w = buttonLeft->getWidth();
    src.h = buttonLeft->getHeight();

    Rectangle::Copy(&src, &dst);

    int bg_draw = (width - buttonLeft->getWidth() - buttonLeft->getWidth()) / buttonBackground->getWidth();
    int start_x = buttonLeft->getWidth();

    surfaceBackground->blit(buttonLeft, &src, &dst);
    surfaceHighlightBackground->blit(buttonHighlightLeft, &src, &dst);

    src.x = 0;
    src.y = 0;
    src.w = buttonRight->getWidth();
    src.h = buttonRight->getHeight();

    Rectangle::Copy(&src, &dst);

    dst.x = width - buttonLeft->getWidth();
    dst.y = 0;

    surfaceBackground->blit(buttonRight, &src, &dst);
    surfaceHighlightBackground->blit(buttonHighlightRight, &src, &dst);

    src.w = buttonBackground->getWidth();
    src.h = buttonBackground->getHeight();
    src.x = 0;
    src.y = 0;

    Rectangle::Copy(&src, &dst);

    for(int i=0; i<bg_draw; i++)
    {
        dst.x = start_x + i;
        surfaceBackground->blit(buttonBackground, &src, &dst);
        surfaceHighlightBackground->blit(buttonHighlightBackground, &src, &dst);
    }

}

std::string DecoratedButton::getCaption()
{
    return stringRenderer.getText();
}

void DecoratedButton::setCaption(std::string m_caption)
{
    stringRenderer.setText(m_caption);
    drawBackground();
}

Surface* DecoratedButton::render()
{
    if( (width == 0 && height == 0) || surfaceBackground == nullptr )
    {
        drawBackground();
    }

    Surface *buffer = new Surface(width, height);

    SDL_Rect src = SDL_Rect();
    SDL_Rect dst = SDL_Rect();

    src.x = 0;
    src.y = 0;
    src.w = surfaceBackground->getWidth();
    src.h = surfaceBackground->getHeight();

    Rectangle::Copy(&src, &dst);
    if(mouseOver)
    {
        buffer->blit(surfaceHighlightBackground, &src, &dst);
    }
    else
    {
        buffer->blit(surfaceBackground, &src, &dst);
    }

    src.w = stringRenderer.getWidth();
    src.h = stringRenderer.getHeight();

    int text_width = width - buttonLeft->getWidth() - buttonRight->getWidth();

    dst.x = ((text_width - stringRenderer.getWidth())/2) + buttonLeft->getWidth();
    dst.y = (height - stringRenderer.getHeight())/2;
    dst.w = stringRenderer.getWidth();
    dst.h = stringRenderer.getHeight();

    buffer->blit(stringRenderer.getSurface(), &src, &dst);

    return buffer;

}

DecoratedButton::~DecoratedButton()
{
    //dtor
    if(surfaceBackground != nullptr)
    {
        delete surfaceBackground;
    }

    if(surfaceHighlightBackground != nullptr)
    {
        delete surfaceHighlightBackground;
    }
}


}
}

#ifdef C_WRAPPER
extern "C"
{
    StiGame::Gui::DecoratedButton* DecoratedButton_new()
    {
        return new StiGame::Gui::DecoratedButton();
    }

    void DecoratedButton_setCaption(StiGame::Gui::DecoratedButton *dbtn, char* text)
    {
        dbtn->setCaption(text);
    }

    const char* DecoratedButton_getCaption(StiGame::Gui::DecoratedButton *dbtn)
    {
        return dbtn->getCaption().c_str();
    }
}
#endif
